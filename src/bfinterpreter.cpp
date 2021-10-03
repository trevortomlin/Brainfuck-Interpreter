#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

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

    std::stack<char> skiploop;
    std::stack<int> loopback;

    for (int i = 0; i < sourceCode->size(); i++){

        std::cout << int(*ptr);

        //std::cout << (*sourceCode)[i] << i;
        switch((*sourceCode)[i]){

            case '>':
                ++ptr;
                break;

            case '<':
                --ptr;
                break;
            
            case '+':
                ++(*ptr);
                break;

            case '-':
                std::cout << "minus";
                --(*ptr);
                break;

            case '.':
                putchar(*ptr);
                break;

            case ',':
                *ptr = getchar();
                break;
            
            case '[':

                if ((*ptr) == 0){


                    skiploop.push('[');

                    while(!skiploop.empty()){

                        ++i;

                        if ((*sourceCode)[i] == '[')
                            skiploop.push('[');
                        
                        else if ((*sourceCode)[i] == ']')
                            skiploop.pop();

                    }

                    ++i;

                }

                else{

                    loopback.push(i);

                }

                break;

            case ']':

                if ((*ptr) != 0){

                    i = loopback.top();
                    loopback.pop();

                }

                break;            

        }

    }
   
}

int main(int argc, char *argv[]){

    if (argc != 2){

        std::cout << "Include Brainfuck file as only argument." << std::endl;

    }

    std::vector<char>* sourceCode = readFile(argv[1]);

    for(std::vector<char>::iterator i = sourceCode->begin(); i != sourceCode->end(); i++){

         std::cout << *i;

    }

    std::cout << std::endl;

    interpret(sourceCode);

    delete sourceCode;

    return 0;
}