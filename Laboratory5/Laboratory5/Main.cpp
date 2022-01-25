#include <iostream>
#include "SmartPointer.h"
#include "HelperFunctions.h"
#include "CTab.h"
#include "CNumber.h"

int main()
{
    CMySmartPointer<int>* pointer1_to_0 = new CMySmartPointer<int>(new int(0));
    CMySmartPointer<int> pointer2_to_0(*pointer1_to_0);
    CMySmartPointer<int> temp_pointer_to_0(pointer2_to_0);
    CMySmartPointer<int> temp_pointer1_to_1(new int(1));
    temp_pointer_to_0 = temp_pointer1_to_1;
    temp_pointer_to_0 = pointer2_to_0;
    temp_pointer1_to_1 = pointer2_to_0;
    delete pointer1_to_0;

    /* Dojdzie tutaj do bledu gdyz zostanie wywolana operacja delete dla pamieci zaalokowanej statycznie
    int error = 0;
    CMySmartPointer<int>* pointer_error = new CMySmartPointer<int>(&error);
    std::cout << "Before deletion" << std::endl;
    delete pointer_error;
    std::cout << "After deletion" << std::endl;
    */

    CTab test = cCreateTab();
    std::cout << std::endl << std::endl;
    int filler1 = iIgnoreResult();
    std::cout << std::endl << std::endl;
    CTab c_tab;
    CTab c_other;
    c_tab = std::move(c_other);
    std::cout << std::endl << std::endl;

    // 4 kopie bez std::move
    // 0 kopii z std::move
    CTable test2 = cCreateTable();
    int filler2 = iIgnoreResultTable();
    CTable test3;
    CTable test4 = test2 + test3;
    CTable test5 = test2 - 3;
    std::cout << std::endl;

    // Test modyfikacji
    std::cout << "Modification" << std::endl;

    CNumber cnumber1;
    CNumber cnumber2;
    cnumber1.setValue(2.5);
    cnumber2.setValue(5.4);
    std::cout << cnumber1.getValue() << std::endl;
    std::cout << cnumber2.getValue() << std::endl << std::endl;

    CNumber cnumber3(cnumber1);
    std::cout << cnumber1.getValue() << std::endl;
    std::cout << cnumber2.getValue() << std::endl;
    std::cout << cnumber3.getValue() << std::endl << std::endl;

    cnumber3 = cnumber2;
    std::cout << cnumber1.getValue() << std::endl;
    std::cout << cnumber2.getValue() << std::endl;
    std::cout << cnumber3.getValue() << std::endl << std::endl;

    CNumber cnumber4 = cnumber1 + cnumber2 + cnumber3;
    std::cout << cnumber1.getValue() << std::endl;
    std::cout << cnumber2.getValue() << std::endl;
    std::cout << cnumber3.getValue() << std::endl;
    std::cout << cnumber4.getValue() << std::endl;

    std::cout << std::endl << std::endl;
}
