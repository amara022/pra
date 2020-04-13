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
		//class rebind<U>有唯一成员other代表allocator<U>
		struct rebind
		{
			typedef allocator<U> other;
		};
		//配置空间，足以存储n个对象，可能用第二个参数增加区域性，仅提示可忽略
		pointer allocate(size_type n, const void* hint = 0)
		{
			return _allocate((difference_type)n, (pointer)0);
		}
		//归还先前配置的空间
		void deallocate(pointer p, size_type n)
		{
			_deallocate(p);
		}
		//同new((const void*)p) T(val)
		void construct(pointer p, const T* val)
		{
			_construct(p, val);
		}
		//释放
		void destroy(pointer p)
		{
			_destory(p);
		}
		//返回对象的地址
		pointer address(reference a)
		{
			return (pointer)&a;
		}
		//返回const对象地址
		const_pointer const_address(const_reference a)
		{
			return (const_pointer)&a;
		}
		//返回可成功配置最大值
		size_type max_size() const
		{
			return size_type(UINT_MAX / sizeof(T));
		}
	};
}
#endif