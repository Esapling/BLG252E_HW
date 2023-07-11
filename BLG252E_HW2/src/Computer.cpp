/* @Author  Enes Fidan
 */
#include <iostream>
#include "Computer.h"
CUDA::CUDA(int numCores)
:m_numCore{numCores}
{
    std::cout << "CUDA is ready" << std::endl;
}
ALU::ALU(int numPerCores)
: m_numPerCores{numPerCores}
{ 
    std::cout << "ALU is ready" << std::endl;
}
GPU::GPU(int numCores)
:m_CUDA{numCores}
{
    std::cout << "GPU is ready" << std::endl;
}
CPU::CPU(int numPerCores)
:m_ALU{numPerCores} // delegates to ALU's constructor
{
    std::cout << "CPU is ready" << std::endl;
}
void GPU::execute(const std::string& opt) const 
{
    if(opt.compare("render") == 0) m_CUDA.render();
    else
        m_CUDA.trainAI();
}
int CPU::execute(const std::string& opt) const
{
    int a, b;
    std::cout << "Enter two integers" << std::endl;
    std::cin>> a >> b ;
    if(opt.compare("add") == 0) return m_ALU.add(a,b);
    else if(opt.compare("subtract")  == 0) return m_ALU.subtract(a,b);
    else return m_ALU.mulitply(a,b);

}
// CUDA Operations
void CUDA::render() const {
    std::cout << "Video is rendered"<< std::endl;
}
void CUDA::trainAI() const {
    std::cout << "AI Model is trained"<< std::endl;
}
// ALU Operations
int ALU::add(int a, int b) const{
    return a + b;
}
int ALU::subtract(int a, int b) const {
    return a - b;
}
int ALU::mulitply(int a, int b) const {
    return a * b;
}
Computer::Computer(){
        std::cout << "Computer is ready"<< std::endl;
        m_CPU = NULL;
        m_GPU = NULL;
}
void Computer::operator+(const CPU& another_cpu){
        
        if(m_CPU != NULL){
            std::cout << "There is already a CPU"<< std::endl;
            return; // already assigned
        }
        else{
            std::cout << "CPU is attached"<< std::endl;
            m_CPU = &another_cpu;
        }
}
void Computer::operator+(const GPU& another_gpu){

        if(m_GPU != NULL){
            std::cout << "There is already a GPU"<< std::endl;
            return; // already assigned
        }
        else{
            m_GPU = &another_gpu;
            std::cout << "GPU is attached"<<std::endl;
        }
        
}

void Computer::execute(const std::string& operationType)const
{
    if(operationType.compare("render") == 0 || operationType.compare("trainModel") == 0)
        m_GPU->execute(operationType);
    else
    {
        std::cout << m_CPU->execute(operationType) << std::endl;
    }

}