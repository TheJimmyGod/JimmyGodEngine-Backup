#pragma once

namespace JimmyGod::Graphics
{
	class ConstantBuffer
	{
	public:
		void Initialize(uint32_t size);
		void Terminate();
		void BindVS(uint32_t slot = 0) const;
		void BindPS(uint32_t slot = 0) const;
		void Update(const void* data) const;
	private:
		ID3D11Buffer* mConstantBuffer = nullptr;
		float mRotation = 0.0f;
	};

	template<class T>
	class TypedConstantBuffer : public ConstantBuffer
	{
	public:
		using DataType = T;

		void Initialize()
		{
			static_assert(sizeof(DataType) % 16 == 0, "[TypedConstantBuffer] data type is must be 16 bytes aligned");
			ConstantBuffer::Initialize(sizeof(DataType));
		}

		void Set(const DataType& data) const
		{
			ConstantBuffer::Update(&data);
		}
	};
}