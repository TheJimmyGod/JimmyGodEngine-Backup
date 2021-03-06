#include "Precompiled.h"
#include "ConstantBuffer.h"

#include "D3DUtil.h"

using namespace JimmyGod;
using namespace JimmyGod::Graphics;
using namespace JimmyGod::Math;

void ConstantBuffer::Initialize(uint32_t size)
{
	auto device = GetDevice();
	// Create Constant buffer first
	D3D11_BUFFER_DESC constantBufferDesc{};
	constantBufferDesc.ByteWidth = size;
	constantBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	constantBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;

	HRESULT hr = device->CreateBuffer(&constantBufferDesc, nullptr, &mConstantBuffer);
	ASSERT(SUCCEEDED(hr), "Failed to create constant buffer");
}

void ConstantBuffer::Terminate()
{
	SafeRelease(mConstantBuffer);
}

void ConstantBuffer::BindVS(uint32_t slot) const
{
	auto context = GetContext();
	context->VSSetConstantBuffers(slot, 1, &mConstantBuffer);
}

void ConstantBuffer::BindPS(uint32_t slot) const
{
	auto context = GetContext();
	context->PSSetConstantBuffers(slot, 1, &mConstantBuffer);
}

void ConstantBuffer::Update(const void * data) const
{
	auto context = GetContext();
	context->UpdateSubresource(mConstantBuffer, 0, nullptr, data, 0, 0);
}