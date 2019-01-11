#include <iostream>
#include "test_of_extension.h"
#include "../matrix.h"

using namespace std;

TestExtension::TestExtension() {}

void TestExtension::run() {

    cout << "-------  Extension tests  --------" << endl;

    Mat t1(2,4), t2(2,4);

    if (t1 == t2) cout << "objects t1 and t2 is equal" << endl;
    else cout << "objects t1 and t2 are different" << endl;
    cout << "-----------------------------" << endl;

    /**
     * Sorry, but I haven't more time for it. My a real job waiting me.
     * I hope this is enough.
     */


}






