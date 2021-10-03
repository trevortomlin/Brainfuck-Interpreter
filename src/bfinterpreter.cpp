#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<char>* readFile(const char *file){

    std::ifstream bfcode(file);
    std::string in;

    std::vector<char> *charVec = new std::vector<char>;

    if (bfcode.is_open()){

        char mychar;
        while (bfcode){

            mychar = bfcode.get();
            
            if (mychar == EOF)
                break;

            charVec->push_back(mychar);
            //std::cout << mychar;
        }       

    }

    bfcode.close();

    return charVec;

}

void interpret(const std::vector<char>* sourceCode){



}

int main(int argc, char *argv[]){

    if (argc != 2){

        std::cout << "Include brainfuck file as only argument." << std::endl;

    }

    std::vector<char>* sourceCode = readFile(argv[1]);

    for(std::vector<char>::iterator i = sourceCode->begin(); i != sourceCode->end(); i++){

         std::cout << *i;

    }

    delete sourceCode;

    return 0;
}