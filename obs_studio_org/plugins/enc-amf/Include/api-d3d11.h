/*
MIT License

Copyright (c) 2016 Michael Fabian Dirks

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

#pragma once

//////////////////////////////////////////////////////////////////////////
// Includes
//////////////////////////////////////////////////////////////////////////
#include "api-base.h"

//////////////////////////////////////////////////////////////////////////
// Code
//////////////////////////////////////////////////////////////////////////

namespace Plugin {
	namespace API {
		class Direct3D11 : public Base {
			virtual std::string GetName() override;
			virtual Type GetType() override;

			virtual std::vector<Adapter> EnumerateAdapters() override;
			virtual Adapter GetAdapterById(uint32_t idLow, uint32_t idHigh) override;
			virtual Adapter GetAdapterByName(std::string name) override;

			virtual void* CreateInstanceOnAdapter(Adapter adapter) override;
			virtual Adapter GetAdapterForInstance(void* pInstance) override;
			virtual void* GetContextFromInstance(void* pInstance) override;
			virtual void DestroyInstance(void* pInstance) override;
		};
	}
}
