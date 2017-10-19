#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <sstream>

std::string GetActiveWindowTitle()
{
    char wnd_title[256];
    HWND hwnd=GetForegroundWindow(); // get handle of currently active window
    GetWindowText(hwnd,wnd_title,sizeof(wnd_title));
    return wnd_title;
}

int main(int argc, char** argv)
{
    bool run = true;

    std::string title="", prev_title="";
    std::stringstream ss;
    std::ofstream out;

    while(run)
    {
        Sleep(1);
        if((GetActiveWindowTitle().find("VLC") != std::string::npos) && (GetActiveWindowTitle().find("Digitally Imported") == std::string::npos))
        {
            title = GetActiveWindowTitle();
            Sleep(100);
            if(prev_title != title)
            {
                out.open("music.txt", std::ios::app);
                prev_title = title;
                title.erase(title.end()-19,title.end()); // Remove " - VLC Media Player"
                std::cout << title << "\n";
                out << title << "\n";
                out.close();
            }
        }
    }


    return 0;
}
