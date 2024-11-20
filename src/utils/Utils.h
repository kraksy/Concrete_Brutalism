
#include <Core.h>

class Utils
{
private:
    /* data */
public:
    Utils(/* args */);
    ~Utils();
    float GetHeightFromTriangle(Vector3 v1, Vector3 v2, Vector3 v3,
                                   Vector3 pos);
    float GetTerrainHeightAtPosition(Vector3 pos, Model terrain,
                                        float scale)
};

Utils::Utils(/* args */)
{
}

Utils::~Utils()
{
}
