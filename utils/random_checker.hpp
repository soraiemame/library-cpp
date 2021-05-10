#ifndef SORAIE_RANDOM_CHECKER
#define SORAIE_RANDOM_CHECKER

#include <iostream>

template<class InputType,class OutputType,OutputType (*solve)(InputType),OutputType (*solve_naive)(InputType),
InputType (*gen_input)(),void (*output_in)(InputType),void (*output_out)(OutputType)>
int random_checker(int tmp = 0){
    auto test = [&](int id){
        InputType testcase = gen_input();
        OutputType out = solve(testcase),out_naive = solve_naive(testcase);
        if(out != out_naive){
            std::cerr << "\033[31mTest failed on test " << id << ". \033[m\n";
            std::cerr << "Test case:\n";
            output_in(testcase);
            std::cerr << "\nsolve output:\n";
            output_out(out);
            std::cerr << "\nsolve naive output:\n";
            output_out(out_naive);
            return 1;
        }
        return 0;
    };
    int i = 1;
    if(tmp == -1){
        while(true){
            if(test(i))return 1;
            i++;
        }
    }
    else{
        for(;i <= tmp;i++){
            if(test(i))return 1;
        }
        std::cerr << "\033[32mNo test failed\n\033[m";
        return 0;
    }
}

#endif /*SORAIE_RANDOM_CHECKER*/