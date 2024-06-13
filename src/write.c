#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

struct _sBmpHeader
{
    char		bm[2];
    uint32_t	size;
    uint32_t	reserve;
    uint32_t	offset;
    uint32_t	header_size;
    uint32_t	width;
    uint32_t	height;
    uint16_t	planes;
    uint16_t	bpp;
    uint32_t	compression;
    uint32_t	bitmap_size;
    uint32_t	hres;
    uint32_t	vres;
    uint32_t	used;
    uint32_t	important;
}__attribute__ ((__packed__));

typedef struct _sBmpHeader sBmpHeader;

void print_bmp_header( sBmpHeader *pHeader )
{
    printf( "ID: %c%c\n", pHeader -> bm[0], pHeader -> bm[1] );
    printf( "Size: %u\n", pHeader -> size );
    printf( "Reserve: %u\n", pHeader -> reserve );
    printf( "Offset: %u\n", pHeader -> offset );
    printf( "Header Size: %u\n", pHeader -> header_size );
    printf( "Width: %u\n", pHeader -> width );
    printf( "Height: %u\n", pHeader -> height );
    printf( "Planes: %u\n", pHeader -> planes );
    printf( "Bits Per Pixel: %u\n", pHeader -> bpp );
    printf( "Compression: %u\n", pHeader -> compression );
    printf( "Bitmap Data Size: %u\n", pHeader -> bitmap_size );
    printf( "H-Resolution: %u\n", pHeader -> hres );
    printf( "V-Resolution: %u\n", pHeader -> vres );
    printf( "Used Colors: %u\n", pHeader -> used );
    printf( "Important Colors: %u\n", pHeader -> important );
    
    return;
}


int main()
{
    FILE	*pFile = NULL;
    FILE    *pFile2 = NULL;
    FILE	*pFile3 = NULL;
    
    if( ( pFile = fopen( "room.bmp", "rb" ) ) == NULL )
    {
        printf( "File could not be opened!\n" );
        return 0;
    }
    
    if( ( pFile2 = fopen( "heroine.bmp", "rb" ) ) == NULL )
    {
        printf( "File could not be opened!\n" );
        return 0;
    }
    
    if( ( pFile3 = fopen( "room_out.bmp", "wb" ) ) == NULL )
    {
        printf( "File could not be opened!\n" );
        return 0;
    }
    
    sBmpHeader	header;
    fread( &header, sizeof( header ), 1, pFile );
    fwrite( &header, sizeof( header ), 1, pFile3 );

    while( !feof( pFile ) )
    {
        uint8_t	original[1024] = {0};
        uint8_t result[1024] = {0};
        uint8_t up_layer[1024] = {0};
        
        size_t count = fread( original, 1, 1024, pFile );
        size_t up = fread(up_layer,1,1024,pFile2);

        for( size_t i = 0 ; i < count ; i++ )
        {
            if(up_layer[i] != 0){
                result[i] = up_layer[i];
            }else{
                result[i] = original[i];
            }
        }
        
        fwrite( result, count, 1, pFile3 );
        
    }
    // fseek(pFile,54,SEEK_SET);
    // while (!feof(pFile2))
    // {
    //     uint8_t color[1024] = {0};
    //     size_t count = fread(color,1,1024,pFile2);
    //     for(int i = 0;i < count;i++){
    //         printf("color[i] = %x\n",color[i]);
    //     }
    // }
    fclose( pFile );
    fclose(pFile2);
    fclose( pFile3 );
    
    return 0;
}