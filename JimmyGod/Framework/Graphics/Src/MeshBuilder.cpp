#include "Precompiled.h"
#include "MeshBuilder.h"
#include "VertexTypes.h"
#include "Mesh.h"
using namespace JimmyGod;
using namespace JimmyGod::Graphics;
using namespace JimmyGod::Math;
MeshPX MeshBuilder::CreateCubePX()
{
	MeshPX mMesh;
	//Front
	mMesh.vertices.emplace_back(VertexPX{ Vector3{ -1.0f,1.0f,-1.0f}, 0.0f,0.0f });
	mMesh.vertices.emplace_back(VertexPX{ Vector3{ 1.0f,1.0f,-1.0f }, 1.0f,0.0f });
	mMesh.vertices.emplace_back(VertexPX{ Vector3{ -1.0f,-1.0f,-1.0f}, 0.0f,1.0f });
	mMesh.vertices.emplace_back(VertexPX{ Vector3{ 1.0f,-1.0f,-1.0f}, 1.0f,1.0f });
	//Right
	mMesh.vertices.emplace_back(VertexPX{ Vector3{ 1.0f,1.0f,-1.0f }, 0.0f,0.0f });
	mMesh.vertices.emplace_back(VertexPX{ Vector3{ 1.0f,1.0f,1.0f }, 1.0f,0.0f });
	mMesh.vertices.emplace_back(VertexPX{ Vector3{ 1.0f,-1.0f,-1.0f }, 0.0f,1.0f });
	mMesh.vertices.emplace_back(VertexPX{ Vector3{ 1.0f,-1.0f,1.0f}, 1.0f,1.0f });
	//Back
	mMesh.vertices.emplace_back(VertexPX{ Vector3{ 1.0f,1.0f,1.0f }, 0.0f,0.0f });
	mMesh.vertices.emplace_back(VertexPX{ Vector3{ -1.0f,1.0f,1.0f }, 1.0f,0.0f });
	mMesh.vertices.emplace_back(VertexPX{ Vector3{ 1.0f,-1.0f,1.0f }, 0.0f,1.0f });
	mMesh.vertices.emplace_back(VertexPX{ Vector3{ -1.0f,-1.0f,1.0f}, 1.0f,1.0f });
	//Left
	mMesh.vertices.emplace_back(VertexPX{ Vector3{ -1.0f,1.0f,1.0f}, 0.0f,0.0f });
	mMesh.vertices.emplace_back(VertexPX{ Vector3{ -1.0f,1.0f,-1.0f }, 1.0f,0.0f });
	mMesh.vertices.emplace_back(VertexPX{ Vector3{ -1.0f,-1.0f,1.0f }, 0.0f,1.0f });
	mMesh.vertices.emplace_back(VertexPX{ Vector3{ -1.0f,-1.0f,-1.0f}, 1.0f,1.0f });
	//Up
	mMesh.vertices.emplace_back(VertexPX{ Vector3{ -1.0f,1.0f,1.0f}, 0.0f,0.0f });
	mMesh.vertices.emplace_back(VertexPX{ Vector3{ 1.0f,1.0f,1.0f }, 1.0f,0.0f });
	mMesh.vertices.emplace_back(VertexPX{ Vector3{ -1.0f,1.0f,-1.0f }, 0.0f,1.0f });
	mMesh.vertices.emplace_back(VertexPX{ Vector3{ 1.0f,1.0f,-1.0f}, 1.0f,1.0f });
	//Bottom
	mMesh.vertices.emplace_back(VertexPX{ Vector3{ 1.0f,-1.0f,-1.0f}, 0.0f,0.0f });
	mMesh.vertices.emplace_back(VertexPX{ Vector3{ -1.0f,-1.0f,-1.0f }, 0.0f,1.0f });
	mMesh.vertices.emplace_back(VertexPX{ Vector3{ 1.0f,-1.0f,1.0f }, 1.0f,0.0f });
	mMesh.vertices.emplace_back(VertexPX{ Vector3{ -1.0f,-1.0f,1.0f}, 1.0f,1.0f });

	//Front
	mMesh.indices.push_back(0);
	mMesh.indices.push_back(1);
	mMesh.indices.push_back(2);
	mMesh.indices.push_back(1);
	mMesh.indices.push_back(3);
	mMesh.indices.push_back(2);
	//Right
	mMesh.indices.push_back(4);
	mMesh.indices.push_back(5);
	mMesh.indices.push_back(6);
	mMesh.indices.push_back(5);
	mMesh.indices.push_back(7);
	mMesh.indices.push_back(6);
	//Back
	mMesh.indices.push_back(8);
	mMesh.indices.push_back(9);
	mMesh.indices.push_back(10);
	mMesh.indices.push_back(9);
	mMesh.indices.push_back(11);
	mMesh.indices.push_back(10);
	//Left
	mMesh.indices.push_back(12);
	mMesh.indices.push_back(13);
	mMesh.indices.push_back(14);
	mMesh.indices.push_back(13);
	mMesh.indices.push_back(15);
	mMesh.indices.push_back(14);
	//Top
	mMesh.indices.push_back(16);
	mMesh.indices.push_back(17);
	mMesh.indices.push_back(18);
	mMesh.indices.push_back(17);
	mMesh.indices.push_back(19);
	mMesh.indices.push_back(18);
	//Bottom
	mMesh.indices.push_back(21);
	mMesh.indices.push_back(20);
	mMesh.indices.push_back(22);
	mMesh.indices.push_back(21);
	mMesh.indices.push_back(22);
	mMesh.indices.push_back(23);
	return mMesh;
}
MeshPX MeshBuilder::CreatePlanePX(float height, float width)
{
	ASSERT((height > 1.0f && width > 1.0f), "Must be more than 1.0 for height and width");
	MeshPX mMesh;
	const float OffsetX = (width) * 0.5f;
	const float OffsetY = (height) * 0.5f;
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			mMesh.vertices.emplace_back(VertexPX
				{ Vector3{
				-OffsetX + (static_cast<float>(x)),
				OffsetY - (static_cast<float>(y)),
				0.0f },
				static_cast<float>((x) / (width - 1.0f)),
				static_cast<float>((y) / (height - 1.0f)) });
		}
	}

	for (int y = 0; y < height - 1; y++)
	{
		for (int x = 0; x < width - 1; x++)
		{
			mMesh.indices.push_back(y*width + x);
			mMesh.indices.push_back((y + 1) * width + x + 1);
			mMesh.indices.push_back((y + 1) * width + x);

			mMesh.indices.push_back(y * width + x);
			mMesh.indices.push_back(y * width + x + 1);
			mMesh.indices.push_back((y + 1)* width + x + 1);
		}
	}
	return mMesh;
}

MeshPX MeshBuilder::CreateCylinderPX(float height, float width)
{
	MeshPX mMesh;
	const float radius = width / 2.0f;
	for (float y = 0.0f; y < height; ++y)
	{
		for (float theta = 0.0f; theta < Constants::TwoPi; theta += (Constants::TwoPi) / (width))
		{
			mMesh.vertices.emplace_back(VertexPX{ Vector3{
				-sinf(theta)* radius,
				static_cast<float>(-y),
				cosf(theta)* radius },
				theta / Constants::TwoPi,y / height });
		}
	}

	for (int y = 0; y <= height; y++)
	{
		for (int x = 0; x <= width; x++)
		{
			if ((y == 0) && (x != 0) && (x != width - 1))
			{
				mMesh.indices.push_back(0);
				mMesh.indices.push_back(0 + x + 1);
				mMesh.indices.push_back(0 + x);
			}
			if ((y == height - 1) && (x != 0) && (x != width - 1))
			{
				mMesh.indices.push_back(y*width);
				mMesh.indices.push_back(y * width + x);
				mMesh.indices.push_back(y * width + x + 1);
			}
			mMesh.indices.push_back(y*width + x);
			mMesh.indices.push_back((y + 1) * width + x + 1);
			mMesh.indices.push_back((y + 1) * width + x);

			mMesh.indices.push_back(y * width + x);
			mMesh.indices.push_back(y * width + x + 1);
			mMesh.indices.push_back((y + 1)* width + x + 1);
		}
	}

	return mMesh;
}

MeshPX MeshBuilder::CreateSpherePX(float radius, int rings, int slices, bool isSpace)
{
	MeshPX mMesh;
	float r = radius;
	
	for (float phi = 0; phi < Constants::Pi; phi += (Constants::Pi) / (rings))
	{
		for (float theta = 0; theta < Constants::TwoPi; theta += (Constants::TwoPi) / (slices))
		{			
			auto vec = Vector3{
						sinf(phi)*cosf(theta)*r,
						cosf(phi)*r,
						sinf(theta) * sinf(phi) *r
			};

			mMesh.vertices.emplace_back(
				VertexPX{
					vec,
					theta / Constants::TwoPi,
					phi / Constants::Pi
				});
		}

	}

	uint32_t a, b, c, d;
	for (uint32_t y = 0; y < rings; ++y)
	{
		for (uint32_t x = 0; x <= slices; ++x)
		{
			a = static_cast<uint32_t>(x % (slices + 1));
			b = static_cast<uint32_t>((x + 1) % (slices + 1));
			c = static_cast<uint32_t>(y * (slices + 1));
			d = static_cast<uint32_t>((y + 1)*(slices + 1));

			if (!isSpace)
			{
				mMesh.indices.push_back(a + c);
				mMesh.indices.push_back(b + c);
				mMesh.indices.push_back(a + d);

				mMesh.indices.push_back(b + c);
				mMesh.indices.push_back(b + d);
				mMesh.indices.push_back(a + d);
			}
			else
			{
				mMesh.indices.push_back(a + d);
				mMesh.indices.push_back(b + c);
				mMesh.indices.push_back(a + c);

				mMesh.indices.push_back(a + d);
				mMesh.indices.push_back(b + d);
				mMesh.indices.push_back(b + c);
			}
		}
	}
	return mMesh;
}

MeshPN MeshBuilder::CreateCylinderPN(float height, float width)
{
	MeshPN mMesh;
	const float radius = width / 2.0f;
	for (float y = 0.0f; y < height; ++y)
	{
		for (float theta = 0.0f; theta < Constants::TwoPi; theta += (Constants::TwoPi) / (width))
		{
			auto vec = Vector3{
				-sinf(theta)* radius,
				static_cast<float>(-y),
				cosf(theta)* radius };

			mMesh.vertices.emplace_back(VertexPN{ vec, Normalize(vec)});
		}
	}

	for (int y = 0; y <= height; y++)
	{
		for (int x = 0; x <= width; x++)
		{
			if ((y == 0) && (x != 0) && (x != width - 1))
			{
				mMesh.indices.push_back(0);
				mMesh.indices.push_back(0 + x + 1);
				mMesh.indices.push_back(0 + x);
			}
			if ((y == height - 1) && (x != 0) && (x != width - 1))
			{
				mMesh.indices.push_back(y*width);
				mMesh.indices.push_back(y * width + x);
				mMesh.indices.push_back(y * width + x + 1);
			}
			mMesh.indices.push_back(y*width + x);
			mMesh.indices.push_back((y + 1) * width + x + 1);
			mMesh.indices.push_back((y + 1) * width + x);

			mMesh.indices.push_back(y * width + x);
			mMesh.indices.push_back(y * width + x + 1);
			mMesh.indices.push_back((y + 1)* width + x + 1);
		}
	}

	return mMesh;
}

MeshPN MeshBuilder::CreateSpherePN(float radius, int rings, int slices, bool isSpace)
{
	MeshPN mMesh;
	float r = radius;

	for (float phi = 0; phi < Constants::Pi; phi += (Constants::Pi) / (rings))
	{
		for (float theta = 0; theta < Constants::TwoPi; theta += (Constants::TwoPi) / (slices))
		{
			auto vec = Vector3{
						sinf(phi)*cosf(theta)*r,
						cosf(phi)*r,
						sinf(theta) * sinf(phi) *r
			};

			mMesh.vertices.emplace_back(
				VertexPN{
					vec,
					Normalize(vec)
				});
		}

	}

	uint32_t a, b, c, d;
	for (uint32_t y = 0; y < rings; ++y)
	{
		for (uint32_t x = 0; x <= slices; ++x)
		{
			a = static_cast<uint32_t>(x % (slices + 1));
			b = static_cast<uint32_t>((x + 1) % (slices + 1));
			c = static_cast<uint32_t>(y * (slices + 1));
			d = static_cast<uint32_t>((y + 1)*(slices + 1));

			if (!isSpace)
			{
				mMesh.indices.push_back(a + c);
				mMesh.indices.push_back(b + c);
				mMesh.indices.push_back(a + d);

				mMesh.indices.push_back(b + c);
				mMesh.indices.push_back(b + d);
				mMesh.indices.push_back(a + d);
			}
			else
			{
				mMesh.indices.push_back(a + d);
				mMesh.indices.push_back(b + c);
				mMesh.indices.push_back(a + c);

				mMesh.indices.push_back(a + d);
				mMesh.indices.push_back(b + d);
				mMesh.indices.push_back(b + c);
			}
		}
	}
	return mMesh;
}

Mesh MeshBuilder::CreateSphere(float radius, int rings, int slices, bool isSpace)
{
	Mesh mMesh;
	float r = radius;

	for (float phi = 0; phi < Constants::Pi; phi += (Constants::Pi) / (rings))
	{
		for (float theta = 0; theta < Constants::TwoPi; theta += (Constants::TwoPi) / (slices))
		{
			auto vec = Vector3{
						sinf(phi)*cosf(theta)*r,
						cosf(phi)*r,
						sinf(theta) * sinf(phi) *r
			};
			auto vec2 = Vector2{ theta / Constants::TwoPi, phi / Constants::Pi }; // Texture coordinate
			auto vecN = Normalize(vec); // Normal
			auto vecT = Vector3{ -vecN.z,0.0f,vecN.x }; // Tangent
			mMesh.vertices.emplace_back(
				Vertex{
					vec,
					vecN,
					vecT,
					vec2
				});
		}

	}

	uint32_t a, b, c, d;
	for (uint32_t y = 0; y < rings; ++y)
	{
		for (uint32_t x = 0; x <= slices; ++x)
		{
			a = static_cast<uint32_t>(x % (slices + 1));
			b = static_cast<uint32_t>((x + 1) % (slices + 1));
			c = static_cast<uint32_t>(y * (slices + 1));
			d = static_cast<uint32_t>((y + 1)*(slices + 1));

			if (!isSpace)
			{
				mMesh.indices.push_back(a + c);
				mMesh.indices.push_back(b + c);
				mMesh.indices.push_back(a + d);

				mMesh.indices.push_back(b + c);
				mMesh.indices.push_back(b + d);
				mMesh.indices.push_back(a + d);
			}
			else
			{
				mMesh.indices.push_back(a + d);
				mMesh.indices.push_back(b + c);
				mMesh.indices.push_back(a + c);

				mMesh.indices.push_back(a + d);
				mMesh.indices.push_back(b + d);
				mMesh.indices.push_back(b + c);
			}
		}
	}
	return mMesh;
}

Mesh MeshBuilder::CreatePlane(float size, int rows, int columns, bool isSpace)
{
	Mesh mMesh;

	const float offsetX = size * -0.5f;
	const float offsetZ = size * -0.5f;
	const float xStep = size / static_cast<float>(rows - 1);
	const float zStep = size / static_cast<float>(columns - 1);
	const float uStep = rows / static_cast<float>(rows - 1);
	const float vStep = columns / static_cast<float>(columns - 1);


	for (int z = 0; z < rows; ++z)
	{
		for (int x = 0; x < columns; ++x)
		{
			float xx = (xStep * x) + offsetX;
			float zz = (zStep * z) + offsetZ;
			float y = 0.0f;

			auto vec = Vector3{
				xx,
				y,
				zz
			};

			auto vec2 = Vector2{ 1.0f - x* uStep, 1.0f - z*vStep }; // Texture coordinate
			auto vecN = Vector3::YAxis; // Normal
			auto vecT = Vector3::XAxis; // Tangent
			mMesh.vertices.emplace_back(
				Vertex{
					vec,
					vecN,
					vecT,
					vec2
				});
		}
	}

	uint32_t index = 0;
	for (uint32_t z = 0; z < rows - 1; ++z)
	{
		for (uint32_t x = 0; x < columns - 1; ++x)
		{
			mMesh.indices.push_back((x + 0) + ((z + 0) * columns));
			mMesh.indices.push_back((x + 0) + ((z + 1) * columns));
			mMesh.indices.push_back((x + 1) + ((z + 1) * columns));

			mMesh.indices.push_back((x + 0) + ((z + 0) * columns));
			mMesh.indices.push_back((x + 1) + ((z + 1) * columns));
			mMesh.indices.push_back((x + 1) + ((z + 0) * columns));
		}
	}
	return mMesh;
}

void MeshBuilder::ComputeNormals(Mesh& mesh)
{
	int indexSize = mesh.indices.size();
	int vertexSize = mesh.vertices.size();

	std::vector<Math::Vector3> normals;
	normals.resize(vertexSize);
	for (uint32_t i = 0; i < indexSize; i += 3)
	{
		uint32_t index_0 = mesh.indices[i + 0];
		uint32_t index_1 = mesh.indices[i + 1];
		uint32_t index_2 = mesh.indices[i + 2];

		auto& vertex_0 = mesh.vertices[index_0];
		auto& vertex_1 = mesh.vertices[index_1];
		auto& vertex_2 = mesh.vertices[index_2];

		Math::Vector3 diff_1 = vertex_1.position - vertex_0.position;
		Math::Vector3 diff_2 = vertex_2.position - vertex_0.position;
		auto tempCross = Math::Normalize(Cross(diff_1, diff_2));
		normals[index_0] += tempCross;
		normals[index_1] += tempCross;
		normals[index_2] += tempCross;
	}
	for (uint32_t i = 0; i < vertexSize; ++i)
	{
		mesh.vertices[i].normal = normals[i];
	}
}

MeshPX MeshBuilder::CreateNDCQuad()
{
	MeshPX mMesh;

	mMesh.vertices.emplace_back(VertexPX{ Vector3{ -1.0f,1.0f,0.0f}, 0.0f,0.0f });
	mMesh.vertices.emplace_back(VertexPX{ Vector3{ 1.0f,1.0f,0.0f }, 1.0f,0.0f });
	mMesh.vertices.emplace_back(VertexPX{ Vector3{ -1.0f,-1.0f,-0.0f}, 0.0f,1.0f });
	mMesh.vertices.emplace_back(VertexPX{ Vector3{ 1.0f,-1.0f,0.0f}, 1.0f,1.0f });

	mMesh.indices.push_back(0);
	mMesh.indices.push_back(1);
	mMesh.indices.push_back(2);

	mMesh.indices.push_back(1);
	mMesh.indices.push_back(3);
	mMesh.indices.push_back(2);

	return mMesh;
}
