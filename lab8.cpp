#include "lab8.h"

int main() {

    BILET bilet,*beg = 0;

    int menu;


    while(true)
    {
        std::cout << "Choose one: " << std::endl;
        std::cout << "1.Get all bilets." << std::endl;
        std::cout << "2.Add new bilet." << std::endl;
        std::cout << "3.Delete a bilet." << std::endl;
        std::cout << "4.Find a bilet." << std::endl;
        std::cout << "5.Cancel a program." << std::endl;
        std::cin >> menu;
        switch(menu)
        {
            case 1:
            {
                get_all_BILETS(beg);
            }break;
            case 2:
            {
                beg = create_BILET(beg, read_BILET());
            }break;
            case 3:
            {
                beg = delete_BILET(beg);
            }break;
            case 4:
            {
                find_BILET(beg);
            }break;
            case 5:
            {
                return 0;
            }
            default:
            {
                std::cout << "Something wrong..." << std::endl;
            }
        }

    }

}


BILET * create_BILET(BILET* beg, BILET * bilet)
{
    BILET * pv = bilet;
    pv->next = 0;

    if(beg)
    {
        BILET * temp = beg;
        while(temp->next)
        {
            temp = temp->next;

        }
        temp->next = pv;
    }else
    {
        beg = pv;
    }
    return beg;
}

BILET * find(BILET * pv, const std::string punkt, BILET ** prev)
{
    *prev = 0;
    while(pv)
    {
        if(pv->punkt == punkt)
        {


            std::cout << "Punkt:" << std::setw(15) << pv->punkt << "; Number:" << std::setw(5) << pv->number_of_avia
                      << "; PIB:" << std::setw(13) << pv->pib[0] << " " << std::setw(2) << pv->pib[1] << " "
                      << std::setw(2) << pv->pib[2] << "; Data: " << std::setw(2) << pv->data[0] << " " << std::setw(2)
                      << pv->data[1] << " " << std::setw(2) << pv->data[2] << std::endl;
            return pv;
        }
        *prev = pv;
        pv = pv->next;


    }
    std::cout << "There is no punkt such as you need." << std::endl;
    return 0;
}

BILET * delete_BILET(BILET * beg)
{
    std::string punkt;
    std::cout << "Which punkt to delete? " << std::endl;
    std::cin >> punkt;
    BILET * prev;
    BILET * pv = find(beg, punkt, &prev);
    if(pv)
    {
        if(pv == beg)
        {
            beg = beg->next;

        }
        else
        {
            prev->next = pv->next;
        }
        delete pv;
    }
    return  beg;

}

void find(BILET * pv, int number)
{
    while(pv)
    {
        if(pv->number_of_avia == number)
        {
            std::cout << "Punkt:" << std::setw(15) << pv->punkt << "; Number:" << std::setw(5) << pv->number_of_avia
                      << "; PIB:" << std::setw(13) << pv->pib[0] << " "<< std::setw(2) << pv->pib[1] << " "
                      <<std::setw(2) << pv->pib[2] << "; Data: " << std::setw(2) << pv->data[0] << " " <<std::setw(2)
                      << pv->data[1] << " " <<std::setw(2) << pv->data[2] << std::endl;
        }
        pv = pv->next;
    }
}


void find(BILET * pv, const int data[3])
{
    while(pv)
    {
        if(pv->data[0] == data[0] && pv->data[1] == data[1] && pv->data[2] == data[2])
        {
            std::cout << "Punkt:" << std::setw(15) << pv->punkt << "; Number:" << std::setw(5) << pv->number_of_avia
                      << "; PIB:" << std::setw(13) << pv->pib[0] << " "<< std::setw(2) << pv->pib[1] << " "
                      <<std::setw(2) << pv->pib[2] << "; Data: " << std::setw(2) << pv->data[0] << " " <<std::setw(2)
                      << pv->data[1] << " " <<std::setw(2) << pv->data[2] << std::endl;
        }
        pv = pv->next;
    }
}


void find_BILET(BILET * beg)
{
    int menu, number, data[3];
    std::cout << "Choose method: " << std::endl;
    std::cout << "1.Find by the number." << std::endl;
    std::cout << "2.Find by the data." << std::endl;
    std::cin >> menu;
    switch(menu)
    {
        case 1:
        {
            std::cout << "Enter number: " << std::endl;
            std::cin >> number;
            find(beg, number);
        }break;
        case 2:
        {
            std::cout << "Enter data: " << std::endl;
            std::cin >> data[0] >> data[1] >> data[2];
            find(beg, data);
        }break;
    }
}

void get_all_BILETS(BILET * beg)
{
    BILET * pv = beg;
    while(pv)
    {
        std::cout << "Punkt:" << std::setw(15) << pv->punkt << "; Number:" << std::setw(5) << pv->number_of_avia
                  << "; PIB:" << std::setw(13) << pv->pib[0] << " "<< std::setw(2) << pv->pib[1] << " "
                  <<std::setw(2) << pv->pib[2] << "; Data: " << std::setw(2) << pv->data[0] << " " <<std::setw(2)
                  << pv->data[1] << " " <<std::setw(2) << pv->data[2] << std::endl;
        pv = pv->next;
    }


}



//entering information about new bilet
BILET * read_BILET()
{
    BILET * bilet = new BILET;

    std::cout << "Enter punkt: " << std::endl;
    std::cin >> bilet->punkt;
    std::cout << "Enter number of avia: " << std::endl;
    std::cin >> bilet->number_of_avia;
    std::cout << "Enter PIB: " << std::endl;
    std::cin >> bilet->pib[0] >> bilet->pib[1] >> bilet->pib[2];
    std::cout << "Enter day, month and year: " << std::endl;
    std::cin >> bilet->data[0] >> bilet->data[1] >> bilet->data[2];


    return  bilet;
}