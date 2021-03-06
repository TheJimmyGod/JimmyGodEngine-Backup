#pragma once

#include <JimmyGodEngine/Inc/JimmyGodEngine.h>

using namespace JimmyGod;
using namespace JimmyGod::Graphics;
using namespace std;
using namespace Math;

class GameState : public JimmyGod::AppState
{
public:
	void Initialize() override;
	void Terminate() override;

	void Update(float deltaTime) override;
	void Render() override;
	void DebugUI() override;
private:
	Camera mCamera;
	MeshBuffer mMeshBuffer;

	VertexShader mEarthVertexShader;
	PixelShader mEarthPixelShader;

	VertexShader mCloudVertexShader;
	PixelShader mCloudPixelShader;

	BlendState mBlendState;

	ConstantBuffer mConstant;
	VertexShader mDomeVertexShader;
	PixelShader mDomePixelShader;
	MeshBuffer mDomeMeshBuffer;
	Texture mSpace;
	MeshPX mMeshX;

	struct TransformData
	{
		JimmyGod::Math::Matrix4 world;
		JimmyGod::Math::Matrix4 wvp;
		JimmyGod::Math::Vector3 viewPosition;
		float padding;
	};

	struct SettingsData
	{
		float specularWeight = 1.0f;
		float bumpMapWeight = 10.0f;
		float normalMapWeight = 1.0f;
		float padding;
	};

	using TransformBuffer = JimmyGod::Graphics::TypedConstantBuffer<TransformData>;
	using LightBuffer = JimmyGod::Graphics::TypedConstantBuffer<JimmyGod::Graphics::DirectionalLight>;
	using MaterialBuffer = JimmyGod::Graphics::TypedConstantBuffer<JimmyGod::Graphics::Material>;
	using SettingsBuffer = JimmyGod::Graphics::TypedConstantBuffer<SettingsData>;

	TransformBuffer mTransformBuffer; 
	LightBuffer mLightBuffer; 
	MaterialBuffer mMaterialBuffer;
	SettingsBuffer mSettingsBuffer;

	SettingsData mSettings;

	DirectionalLight mDirectionalLight;
	Material mMaterial;
	
	float mCloudRotation = 0.0f;

	Mesh mMesh;
	Texture mEarth;
	Texture mEarthDisplacement;
	Texture mEarthSpecualr;
	Texture mNormalMap;
	Texture mNightMap;
	Texture mEarthCould;
	Sampler mSampler;
	Vector3 mRotation = 0.0f;
};