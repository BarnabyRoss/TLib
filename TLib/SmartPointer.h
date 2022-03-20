#ifndef __SMARTPOINTER_H__
#define __SMARTPOINTER_H__

namespace TLib{

template < typename T >
class SmartPointer{

public:
  SmartPointer(T* pointer){

    this->m_pointer = pointer;
  }

  SmartPointer(const SmartPointer<T>& obj){

    this->m_pointer = obj.m_pointer;
    const_cast<SmartPointer<T>&>(obj).m_pointer = nullptr;
  }

  SmartPointer<T>& operator = (const SmartPointer<T>& obj){

    if( this != obj ){

      delete this->m_pointer;
      this->m_pointer = obj.m_pointer;
      const_cast<SmartPointer<T>&>(obj).m_pointer = nullptr;
    }

    return *this;
  }

  T* operator -> (){

    return this->m_pointer;
  }

  T& operator * (){

    return *this->m_pointer;
  }

  bool isNULL(){

    return this->m_pointer == nullptr;
  }

  T* get(){

    return this->m_pointer;
  }

  ~SmartPointer(){

    delete this->m_pointer;
  }

protected:
  T* m_pointer;
};

}

#endif // __SMARTPOINTER_H__
