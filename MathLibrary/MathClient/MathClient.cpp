// MathClient.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vector3.h"
#include "Matrix4.h"
using namespace MathLibraryJSS;

void PrintVec4(const Vector4& refVec4)
{
    std::cout << "\n\n PrintVec4";
    std::cout << "\n" << refVec4.X() << "\t" << refVec4.Y() << "\t" << refVec4.Z() << "\t" << refVec4.Z();
}

void PrintMat4(MathLibraryJSS::Matrix4& refMat4)
{    
    std::cout << "\n\n PrintMat4";
    std::cout << "\n" << refMat4.Xx() << "\t\t" << refMat4.Xy() << "\t\t" << refMat4.Xz() << "\t\t" << refMat4.Xw();
    std::cout << "\n" << refMat4.Yx() << "\t\t" << refMat4.Yy() << "\t\t" << refMat4.Yz() << "\t\t" << refMat4.Yw();
    std::cout << "\n" << refMat4.Zx() << "\t\t" << refMat4.Zy() << "\t\t" << refMat4.Zz() << "\t\t" << refMat4.Zw();
    std::cout << "\n" << refMat4.Tx() << "\t\t" << refMat4.Ty() << "\t\t" << refMat4.Tz() << "\t\t" << refMat4.Tw();
    
}

int main()
{
    Vector4 vec1 = { 0,0,1,0 };
    
    Matrix4 testMat;
    testMat.SetRotateY(90);
    
    Vector4 rotatedVec = testMat * vec1;
    PrintVec4(rotatedVec);

    Matrix4 testMat2;
    testMat2.SetRotateZ(90);        

    Vector4 rotatedVec1 = testMat2 * rotatedVec;
    PrintVec4(rotatedVec1);

    
    int i = 0;

}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
