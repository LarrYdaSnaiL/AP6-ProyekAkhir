#include <fstream>
#include <iostream>
#include <ctime>
#include <vector>
#include "__Header__/header.h"
using namespace std;

struct pelapor
{
    string nama;
    string hilang;
    string alamat;
};

void printPelapor(pelapor lapor)
{
    system("cls");

    cout << "=============================================" << endl;
    cout << "Nama Pelapor: " << lapor.nama << endl;
    cout << "Barang yang Hilang: " << lapor.hilang << endl;
    cout << "Alamat Pelapor: " << lapor.alamat << endl;
    cout << "=============================================" << endl;
    cout << "       Terima Kasih atas Laporan Anda!       " << endl;
    cout << "    Laporan Anda akan Segera Kami Proses!    " << endl;
    cout << "=============================================" << endl;
    system("pause");
}

int main()
{
    ifstream outputFile("__Laporan__/pelaporan.txt");
    pelapor lapor;

    cout << "Masukkan Nama Pelapor: ";
    getline(cin, lapor.nama);

    cout << "Masukkan Barang yang Hilang: ";
    getline(cin, lapor.hilang);

    cout << "Masukkan Alamat Pelapor: ";
    getline(cin, lapor.alamat);

    if (outputFile)
    {
        if (outputFile.is_open())
        {
            vector<string> lines;
            string line;

            while (getline(outputFile, line))
            {
                lines.push_back(line);
            }

            outputFile.close();

            if (lines.size() >= 3)
            {
                lines[2] = "Laporan Terakhir: " + getDateTime();
            }

            ofstream lastModifiedTime("__Laporan__/pelaporan.txt");

            for (const auto &line : lines)
            {
                lastModifiedTime << line << endl;
            }

            lastModifiedTime.close();

            ofstream inputFile("__Laporan__/pelaporan.txt", ios::app);

            if (inputFile.is_open())
            {
                inputFile << "Nama Pelapor: " << lapor.nama << "\n";
                inputFile << "Barang yang Hilang: " << lapor.hilang << "\n";
                inputFile << "Alamat Pelapor: " << lapor.alamat << "\n";
                inputFile << "=============================================\n";
                inputFile.close();
                printPelapor(lapor);
            }
            else
            {
                cerr << "Error opening file\n";
            }
        }
        else
        {
            cerr << "Error opening file\n";
        }
    }
    else
    {
        ofstream inputFile("__Laporan__/pelaporan.txt");

        if (inputFile.is_open())
        {
            inputFile << "File Created\n";
            inputFile << "Laporan Dibuat: " << getDateTime() << "\n";
            inputFile << "Pelaporan Terakhir: " << getDateTime() << "\n";
            inputFile << "=============================================\n";
            inputFile << "Nama Pelapor: " << lapor.nama << "\n";
            inputFile << "Barang yang Hilang: " << lapor.hilang << "\n";
            inputFile << "Alamat Pelapor: " << lapor.alamat << "\n";
            inputFile << "=============================================\n";
            inputFile.close();
            printPelapor(lapor);
        }
        else
        {
            cerr << "Error opening file\n";
        }
    }

    return 0;
}