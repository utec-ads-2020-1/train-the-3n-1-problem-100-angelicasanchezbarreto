//
// Created by lica-pc on 3/28/20.
//

#include <sstream>
#include <iterator>
#include "funciones.h"

template <typename T>
int max(vector<T> cyclelengths)
{
    int max = cyclelengths[0];
    for(int num : cyclelengths)
    {
        if(max<num)
            max=num;
    }
    return max;
}

int tres_n_uno(string numeros)
{
    while(getline(cin,numeros))
    {
        vector<int> cyclelengths;
        int maximo=0;
        if (numeros.empty())
            break;
        else
        {
            istringstream esp(numeros);
            vector<string> arr((istream_iterator<string>(esp)),istream_iterator<string>());
            int num1 = stoi(arr[0]), num2 = stoi(arr[1]), resultado;
            if(arr.size()==2)
            {
                for(int i=num1; i<=num2; i++)
                {
                    int length=1;
                    int temp=i;
                    while(temp!=1)
                    {
                        if (temp % 2 != 0)
                            temp = 3 * temp + 1;
                        else
                            temp = temp / 2;
                        length++;
                    }
                    cyclelengths.push_back(length);
                }
            }
            maximo = max<int>(cyclelengths);
            cout << num1 << " " << num2 << " " << maximo << endl;

        }
    }
}