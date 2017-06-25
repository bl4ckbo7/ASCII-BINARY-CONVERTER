/*
*PROGRAM: ASCII-BINARY CONVERTER
*AUTHOR: ANDY W. KAWA
*VERSION: 0.1.2017
*DATE: July 15, 2017.
*/

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <math.h>
#include <fstream>

int main()
{
    system("color 0a");
    system("title ASCII-BINARY CONVERTER v0.1.2017");
    int digit[1000], len, base(2), rem[8], j(0), k(8);
    std::string ch;

    std::cout<<"\n"<<"\t \tASCII TO BINARY CONVERTER V0.1.2017";
    std::cout<<"\n"<<"\t\t\tCREATED BY ANDY KAWA\n\n";
    std::cout<<"\nASCII(STRING): ";
    getline(std::cin,ch);
    std::cout<<"\n\n";

    //calc the length of ch
    len = ch.length();

    for(int i=0; i<len; i++){
        digit[i] = static_cast<int>(ch[i]);
    }

    //file stream section begins here
    std::ofstream writeFile;
    writeFile.open("ASCII-BINARY.txt");

    std::cout<<"DECIMAL: ";
    for(int l=0; l<len; l++){
        std::cout<<digit[l]<<" ";
        writeFile<<digit[l]<<" ";
    }

    std::cout<<"\n\n\n";
    writeFile<<"\n\n\n";

    std::cout<<"HEXADECIMAL: ";
    for(int n=0; n<len; n++){
        std::cout<<std::hex<<digit[n]<<" ";
        writeFile<<std::hex<<digit[n]<<" ";
    }

    std::cout<<"\n\n\n";
    writeFile<<"\n\n\n";

    std::cout<<"BINARY: ";
    for(int m=0; m<len; m++){
        while(digit[m]>0||j<8){
            //finds the remainder of the number
                rem[j] = digit[m]%base;
            //divides the number by the base value choosed
                digit[m] = digit[m]/base;
            //increments the array value
                j++;
            }

        while(k>0){
                //outputs the binaries
                std::cout<<rem[k-1];
                writeFile<<rem[k-1];
                //decrements the array value
                k--;
            }
        std::cout<<" "; //output the space after binary value here
        writeFile<<" ";

        //resets the iterators
        j = 0;
        k = 8;

    }

    std::cout<<"\n\n\n";
    writeFile<<"\n\n\n";

    writeFile.close();
    //file stream section ends here

    return 0;
}
