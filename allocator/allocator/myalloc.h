#ifndef _MYALLOC_
#define _MYALLOC_

#include <new>
#include <cstddef>
#include <cstdlib>
#include <climits>
#include <iostream>

namespace MY
{
	template <class T>
	inline T* _allocate(ptrdiff_t size, T*)
	{
		set_new_handler(0);
		T* tmp = (T*)(::operator new((size_t)(size*sizeof(T))));
		if (tmp == 0)
		{
			cout << "out of memory" << endl;
			exit(1);
		}
		return tmp;
	}
	template <class T>
	inline void _deallocate(T* buffer)
	{
		::operator delete(buffer);
	}
	
	template <class T1,class T2>
	inline void _construct(T1* p, T2* val)
	{
		new(p)T1(val);
	}

	template <class T>
	inline void _destory(T* ptr)
	{
		ptr->~T();
	}

	template <class T>
	class allocator
	{
	public:
		typedef T val_type;
		typedef T* pointer;
		typedef const T* const_pointer;
		typedef T& reference;
		typedef const T& const_reference;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;

		template <class U>
		//class rebind<U>��Ψһ��Աother����allocator<U>
		struct rebind
		{
			typedef allocator<U> other;
		};
		//���ÿռ䣬���Դ洢n�����󣬿����õڶ����������������ԣ�����ʾ�ɺ���
		pointer allocate(size_type n, const void* hint = 0)
		{
			return _allocate((difference_type)n, (pointer)0);
		}
		//�黹��ǰ���õĿռ�
		void deallocate(pointer p, size_type n)
		{
			_deallocate(p);
		}
		//ͬnew((const void*)p) T(val)
		void construct(pointer p, const T* val)
		{
			_construct(p, val);
		}
		//�ͷ�
		void destroy(pointer p)
		{
			_destory(p);
		}
		//���ض���ĵ�ַ
		pointer address(reference a)
		{
			return (pointer)&a;
		}
		//����const�����ַ
		const_pointer const_address(const_reference a)
		{
			return (const_pointer)&a;
		}
		//���ؿɳɹ��������ֵ
		size_type max_size() const
		{
			return size_type(UINT_MAX / sizeof(T));
		}
	};
}
#endif