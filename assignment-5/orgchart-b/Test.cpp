#include "doctest.h"
#include <iostream>
// #include "OrgChart.hpp"
#include "sources/OrgChart.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Initialization")
{
    OrgChart organization;
    organization.add_root("CEO")
        .add_sub("CEO", "CTO")    // Now the CTO is subordinate to the CEO
        .add_sub("CEO", "CFO")    // Now the CFO is subordinate to the CEO
        .add_sub("CEO", "COO")    // Now the COO is subordinate to the CEO
        .add_sub("CTO", "VP_SW")  // Now the VP Software is subordinate to the CTO
        .add_sub("COO", "VP_BI"); // Now the VP_BI is subordinate to the COO

    SUBCASE("Checking names")
    {
        CHECK(organization.getRoot()._name == "CEO");

        CHECK(organization.getRoot().childs[0]->_name == "CTO");
        CHECK(organization.getRoot().childs[1]->_name == "CFO");
        CHECK(organization.getRoot().childs[2]->_name == "COO");

        CHECK(organization.getRoot().childs[0]->childs[0]->_name == "VP_SW");
        CHECK(organization.getRoot().childs[2]->childs[0]->_name == "VP_BI");
    }

    SUBCASE("overriding root")
    {
        CHECK_NOTHROW(organization.add_root("CEO"));
        CHECK(organization.getRoot()._name == "CEO");
        CHECK_NOTHROW(organization.add_root("CEO2")); // overriding root
        CHECK(organization.getRoot()._name == "CEO2");
        CHECK_NOTHROW(organization.add_root("CEO3")); // overriding root
        CHECK(organization.getRoot()._name == "CEO3");
    }
    SUBCASE("Add sub before root")
    {
        OrgChart organization1;
        CHECK_THROWS(organization1.add_sub("SUB1", "SUB2"));
        CHECK_THROWS(organization1.add_sub("SUB3", "SUB2"));
        CHECK_THROWS(organization1.add_sub("SUB4", "SUB2"));
    }

    SUBCASE("overriding root after adding sub")
    {
        OrgChart organization2;
        organization2.add_root("CEO")
            .add_sub("CEO", "CTO")    // Now the CTO is subordinate to the CEO
            .add_sub("CEO", "CFO")    // Now the CFO is subordinate to the CEO
            .add_sub("CEO", "COO")    // Now the COO is subordinate to the CEO
            .add_sub("CTO", "VP_SW")  // Now the VP Software is subordinate to the CTO
            .add_sub("COO", "VP_BI"); // Now the VP_BI is subordinate to the COO
        CHECK(organization2.getRoot()._name == "CEO");
        CHECK_NOTHROW(organization2.add_root("CEO2"));
        CHECK(organization2.getRoot()._name == "CEO2");
    }
    SUBCASE("Checking the number of children")
    {

        CHECK(organization.getRoot().childs.size() == 3);

        CHECK(organization.getRoot().childs[0]->childs.size() == 1);
        CHECK(organization.getRoot().childs[1]->childs.size() == 0);
        CHECK(organization.getRoot().childs[2]->childs.size() == 1);

        CHECK(organization.getRoot().childs[0]->childs[0]->childs.size() == 0);
        CHECK(organization.getRoot().childs[2]->childs[0]->childs.size() == 0);
    }

    SUBCASE("Adding an employee with this name to an existing employee")
    {
        OrgChart organization3;
        organization3.add_root("CEO")
            .add_sub("CEO", "CTO")    // Now the CTO is subordinate to the CEO
            .add_sub("CEO", "CFO")    // Now the CFO is subordinate to the CEO
            .add_sub("CEO", "COO")    // Now the COO is subordinate to the CEO
            .add_sub("CTO", "VP_SW")  // Now the VP Software is subordinate to the CTO
            .add_sub("COO", "VP_BI"); // Now the VP_BI is subordinate to the COO

        CHECK_THROWS(organization3.add_sub("CEO", "CTO"));
    }

    SUBCASE("Checking the number of employees in the organization")
    {
        OrgChart organization3;
        CHECK(organization3.getNumberEmployee() == 0);
        organization3.add_root("CEO");
        CHECK(organization3.getNumberEmployee() == 1);
        organization3.add_sub("CEO", "CTO");   // Now the CTO is subordinate to the CEO
        organization3.add_sub("CEO", "CFO");   // Now the CFO is subordinate to the CEO
        organization3.add_sub("CEO", "COO");   // Now the COO is subordinate to the CEO
        organization3.add_sub("CTO", "VP_SW"); // Now the VP Software is subordinate to the CTO
        CHECK(organization3.getNumberEmployee() == 5);
        organization3.add_sub("COO", "VP_BI"); // Now the VP_BI is subordinate to the COO
        CHECK(organization3.getNumberEmployee() == 6);
        CHECK_THROWS(organization3.add_sub("CEO", "CTO"));
    }
    SUBCASE("Print")
    {
        OrgChart organization4;
        organization4.add_root("CEO")
            .add_sub("CEO", "CTO") // Now the CTO is subordinate to the CEO
            .add_sub("CEO", "CFO") // Now the CFO is subordinate to the CEO
            .add_sub("CEO", "COO") // Now the COO is subordinate to the CEO

            .add_sub("CTO", "VP_SW")   // Now the VP Software is subordinate to the CTO
            .add_sub("CTO", "VP_SW_1") // Now the VP Software is subordinate to the CTO
            .add_sub("CTO", "VP_SW_2") // Now the VP Software is subordinate to the CTO

            .add_sub("COO", "VP_BI")   // Now the VP_BI is subordinate to the COO
            .add_sub("COO", "VP_BI_1") // Now the VP_BI is subordinate to the COO
            .add_sub("COO", "VP_BI_2") // Now the VP_BI is subordinate to the COO

            .add_sub("CFO", "VP_BI_8")  // Now the VP_BI is subordinate to the COO
            .add_sub("CFO", "VP_BI_9")  // Now the VP_BI is subordinate to the COO
            .add_sub("CFO", "VP_BI_10") // Now the VP_BI is subordinate to the COO

            .add_sub("VP_BI", "VP_BI_11") // Now the VP_BI is subordinate to the COO
            .add_sub("VP_BI", "VP_BI_12") // Now the VP_BI is subordinate to the COO

            .add_sub("VP_BI_1", "VP_BI_13") // Now the VP_BI is subordinate to the COO
            .add_sub("VP_BI_1", "VP_BI_14") // Now the VP_BI is subordinate to the COO

            .add_sub("VP_SW_1", "VP_BI_15")  // Now the VP_BI is subordinate to the COO
            .add_sub("VP_SW_1", "VP_BI_16"); // Now the VP_BI is subordinate to the COO

        cout << organization4 << endl;
    }
}
TEST_CASE("Order tree")
{
    
    OrgChart organization;
    organization.add_root("CEO").add_sub("CEO", "CTO").add_sub("CEO", "CFO").add_sub("CEO", "COO")
        .add_sub("CTO", "VP_SW")
        .add_sub("COO", "VP_BI");

    SUBCASE("pre-Order")
    {




    }

    SUBCASE("level-Order")
    {
    }
    SUBCASE("reverse-level-Order")
    {
    }

    cout << organization << endl;
}
