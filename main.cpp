#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <string>
#include <algorithm>
using namespace std;

void generate(void);
bool compare(void);
void run(string name);

string name1 = "1135";
string name2 = "tmp";

int main(void)
{
    for (int i = 0; i < 1; i++)
    {
        cout << "TEST\t" << i << endl;
        generate();
        try
        {
            // run(name1);
        }
        catch (int e)
        {
            cout << "error" << endl;
        }
        cout << endl;
        // bool res = compare();
        // cout << (res ? "true" : "false") << endl;
        // if (res == false)
        //     system("pause");
        //
    }
    system("pause");
    return 0;
}

int ge(int *tree, int n, int min_, int max_)
{
    if (n == 0)
        return 0;
    if (n == 1)
    {
        tree[0] = rand() % (max_ - min_) + min_ * ((rand() % 2) == 1 ? 1 : -1);
        return 0;
    }
    int l = rand() % (n - 1);
    int r = n - 1 - l;
    int c = 0;
    while (c - min_ < l || max_ - c < r)
    {
        c = rand() % (max_ - min_) + min_;
    }
    tree[0] = c * ((rand() % 1) == 1 ? 1 : -1);

    ge(tree + 1, l, min_ + 1, c);
    ge(tree + l + 1, r, c, max_ - 1);
    return 0;
}
void generate(void)
{
    ofstream outfile;
    outfile.open("data.txt");
    srand(time(NULL));
    //generate content
    int n = rand() % 40;
    int *tree = (int *)malloc(sizeof(int) * n);
    ge(tree, n, 1, 1000);
    outfile << "1" << endl
            << n << endl;
    for (int i = 0; i < n; i++)
    {
        outfile << tree[i] << " ";
    }
    //
    outfile.close();
}
void run(string name)
{
    string str = name + ".exe";
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // if (argc != 2)
    // {
    //     printf("Usage: %s [cmdline]\n", argv[0]);
    //     return 0;
    // }

    TCHAR *path = new TCHAR[str.size() + 1];
    path[str.size()] = 0;
    //As much as we'd love to, we can't use memcpy() because
    //sizeof(TCHAR)==sizeof(char) may not be true:
    copy(str.begin(), str.end(), path);
    // Start the child process.
    if (!CreateProcess(NULL,  // No module name (use command line)
                       path,  // Command line
                       NULL,  // Process handle not inheritable
                       NULL,  // Thread handle not inheritable
                       FALSE, // Set handle inheritance to FALSE
                       0,     // No creation flags
                       NULL,  // Use parent's environment block
                       NULL,  // Use parent's starting directory
                       &si,   // Pointer to STARTUPINFO structure
                       &pi)   // Pointer to PROCESS_INFORMATION structure
    )
    {
        printf("CreateProcess failed (%d).\n", GetLastError());
    }

    // Wait until child process exits.
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Close process and thread handles.
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

bool compare(void)
{
    ifstream data1, data2;
    data1.open(name1 + ".txt");
    data2.open(name2 + ".txt");
    string str1, str2;
    int i = -1;
    while (getline(data1, str1) && getline(data2, str2))
    {
        if (i == -1)
            i = 0;
        i += str1.compare(str2);
    }
    return i == 0;
}