#pragma once
/*
MIT License
Copyright (c) 2021 SAE Institute Geneva
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <iostream>
#include <type_traits>

namespace maths
{
	template<typename T>
	class Unique_Ptr {

	public:

		//default constr
		Unique_Ptr() = default;
		//explicit constr
		explicit Unique_Ptr(T* t) : Uptr_(t) {}
		// destr
		~Unique_Ptr()
		{
			if (Uptr_ != nullptr) { delete Uptr_; }
		}
		//copy
		Unique_Ptr& operator=(const Unique_Ptr& t) = delete;
		//move
		Unique_Ptr& operator= (Unique_Ptr&& t) noexcept {

			Uptr_ = std::move(t.Uptr_);
			return *this;
		}

		T* operator->() const { return Uptr_; }
		T& operator*()  const { return *Uptr_; }

	private:
		T* Uptr_;

	};
}