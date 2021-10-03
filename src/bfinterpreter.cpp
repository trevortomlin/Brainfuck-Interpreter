#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<char> *readFile(const char *file){

    std::ifstream bfcode(file);
    std::vector<char> *charVec = new std::vector<char>;

    if (bfcode.is_open()){

        char mychar;
        while (bfcode){

            mychar = bfcode.get();
            
            if (mychar == EOF)
                break;

            charVec->push_back(mychar);

        }

        bfcode.close();       

    }

    return charVec;

}

void interpret(std::vector<char> *sourceCode){

    char array[30000] = {0};
    char *ptr = array;

    for (int i = 0; i < sourceCode->size(); i++){

        switch((*sourceCode)[i]){

            case '>':
                ++ptr;
                break;

            case '<':
                --ptr;
                break;
            
            case '+':
                ++*ptr;
                break;

            case '-':
                --*ptr;
                break;

            case '.':
                putchar(*ptr);
                break;

            case ',':
                *ptr = getchar();
                break;
            
            case '[':
                break;

            case ']':
                break;            

        }

    }
   

}

int main(int argc, char *argv[]){

    if (argc != 2){

        std::cout << "Include brainfuck file as only argument." << std::endl;

    }

    std::vector<char>* sourceCode = readFile(argv[1]);

    for(std::vector<char>::iterator i = sourceCode->begin(); i != sourceCode->end(); i++){

         std::cout << *i;

    }

    interpret(sourceCode);

    delete sourceCode;

    return 0;
}