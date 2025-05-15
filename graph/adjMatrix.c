#include <stdio.h>
#include "adjMatrix.h"
#include <stdlib.h>

int createGraph()
{
    graph new = (graph)malloc(sizeof(matrix));
    printf("VertexCount, ArcCount: ");
    scanf("%d %d", &new->vexCount, &new->arcCount);
    new->Vertex = (Vextype*)malloc(sizeof(Vextype) * new->vexCount);
    new->arcs = (Adjtype**)malloc(sizeof(Adjtype *) * new->arcCount);
    for (int i = 0; i < new->vexCount; i++)
    {
        new->arcs[i] = (Adjtype *)calloc(new->vexCount, sizeof(Adjtype));
    }
    
    for (int i = 0; i < new->vexCount; i++)
    {
        scanf("%d", )
    }
    
}