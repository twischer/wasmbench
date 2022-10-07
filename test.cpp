#include <iostream>
#include <time.h>

int main()
{
        unsigned long tmp, a = 0, b = 1;

        //std::cout << a << std::endl;
        //std::cout << b << std::endl;

        std::cout << "Started!" << std::endl;

        time_t t1 = time(NULL);

        for (unsigned long i = 0uL; i < 10000uL; ++i)
        {
            for (unsigned long j = 0uL; j < 1000000uL; ++j)
            {
                    tmp = b;
                    b = a + b;
                    a = tmp;

                    //std::cout << b << std::endl;
            }
        }

        time_t t2 = time(NULL);
        time_t dt = t2 - t1;

        std::cout << "Finished!" << std::endl;

        std::cout << "Result: " << b << std::endl;
        std::cout << "Time: " << dt << "s" << std::endl;

        return 0;
}

