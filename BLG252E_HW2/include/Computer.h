/* @Author  Enes Fidan
 */
#ifndef COMPUTER_H
#define COMPUTER_H

class ALU{
    // arithmetic logic unit that executes operations in the cpu
public:
    ALU() = delete;
    ALU(int);
    int add(int, int) const ;
    int subtract(int , int)const ;
    int mulitply(int , int)const ;
private:
    int m_numPerCores;
};



class CUDA{
public:
    CUDA() = delete;
    CUDA(int);
    void render()const ;
    void trainAI() const;

private:
    int m_numCore;
};

class GPU{
public:
    GPU(int);
    void execute(const std::string&) const;
private:
    CUDA m_CUDA;
};
class CPU{
public:
    CPU(int);
    int execute(const std::string&) const;
private:
    ALU m_ALU;
};


class Computer{
public:
    Computer();
    void operator+(const CPU& another_cpu);
    void operator+(const GPU& another_gpu);
    void execute(const std::string&) const;
private:
    const CPU* m_CPU;  // attributes of m_CPU dont change
    const GPU* m_GPU; // attributes of m_GPU dont change
                      // composition relationship
};

#endif