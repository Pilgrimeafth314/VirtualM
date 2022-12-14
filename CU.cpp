#include "CU.h"

CU::CU() {}

CU::CU(string s, Register *_r, ALU _alu) : status(s), alu(_alu)
{
    _r = registers;
}

Instruction *CU::fetch(Program *program, int index, int flag)
{
    if (flag)
    {
        setStatus("Fetch");
        displayStatus();
    }
    return program->getInstruction(index);
}

int CU::decode(Instruction *in)
{
    setStatus("Decode");
    displayStatus();
    return in->getCode();
}

Register *CU::execute(int _code, Instruction *in)
{
    Register *aux = new Register();
    setStatus("Execute");
    displayStatus();
    switch (_code)
    {
    case 50:
        cout << "START" << endl;
        break;
    case 51:
        cout << "END" << endl;
        break;
    case 80:
    {
        cout << in->getName();
        auto *ptr_add = static_cast<ADD *>(in);
        cout << " " << ptr_add->getOperand1() << ", ";
        cout << ptr_add->getOperand2() << endl;
        //cout << "Result: " << alu.Add(ptr_add->getOperand1(), ptr_add->getOperand2());
        aux->setValue(alu.Add(ptr_add->getOperand1(), ptr_add->getOperand2()));
        cout << aux->getValue() << endl;
    }
    break;
    case 81:
    {
        cout << in->getName();
        auto *ptr_mult = static_cast<MULT *>(in);
        cout << " " << ptr_mult->getOperand1() << ", ";
        cout << ptr_mult->getOperand2() << endl;
        //cout << "Result: " << alu.Mult(ptr_mult->getOperand1(), ptr_mult->getOperand2());
        aux->setValue(alu.Mult(ptr_mult->getOperand1(), ptr_mult->getOperand2()));
        cout << aux->getValue() << endl;
    }
    break;
    case 82:
    {
        cout << in->getName();
        auto *ptr_div = static_cast<DIV *>(in);
        cout << " " << ptr_div->getOperand1() << ", ";
        cout << ptr_div->getOperand2() << endl;
        //cout << "Result: " << alu.Div(ptr_div->getOperand1(), ptr_div->getOperand2());
        aux->setValue(alu.Div(ptr_div->getOperand1(), ptr_div->getOperand2()));
        cout << aux->getValue() << endl;
    }
    break;
    case 83:
    {
        cout << in->getName();
        auto *ptr_rest = static_cast<REST *>(in);
        cout << " " << ptr_rest->getOperand1() << ", ";
        cout << ptr_rest->getOperand2() << endl;
        //cout << "Result: " << alu.Rest(ptr_rest->getOperand1(), ptr_rest->getOperand2());
        aux->setValue(alu.Rest(ptr_rest->getOperand1(), ptr_rest->getOperand2()));
        cout << aux->getValue() << endl;
    }
    break;
    
    case 84:
    {
        cout << in->getName();
    }
    break;
    default:
        break;
    }
    return aux;
}

void CU::setStatus(string _status)
{
    status = _status;
}

void CU::displayStatus()
{
    cout << "\n" << status << "\n";
}