typedef int Vextype;
typedef float Adjtype;
typedef struct adjMatrix
{
    Vextype *Vertex;
    Adjtype **arcs;
    int vexCount, arcCount;
} matrix, *graph;

