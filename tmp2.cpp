//摘自msdn的示例代码
#include <windows.h>
#include <stdio.h>
#include <string>
#include <tchar.h>
using namespace std;
int _tmain(int argc, TCHAR *argv[])
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));


    string str = "tmp.exe";
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
        return 0;
    }

    // Wait until child process exits.
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Close process and thread handles.
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}