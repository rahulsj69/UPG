#include <stdio.h>
#include <C:\Users\Jahagirdar\Documents\Visual Studio 2010\Projects\CRCRec\CRCRec\FastCRC.h>
#include <sys\stat.h>
#include <string.h>
#include <stdlib.h>


#define BUFF_SIZE  1024
unsigned long check_crc,check_crc_calculate;
unsigned long Atohex(char *String);
unsigned long Atohex(char *String)
{
   unsigned long Value = 0, Digit;
   unsigned char c;

    if(String[0]=='0' && (String[1]=='x' || String[1]=='X'))
        String+=2;

    while ((c = *String++) != 0) {
        if (c >= '0' && c <= '9')
            Digit = (unsigned long) (c - '0');
        else if (c >= 'a' && c <= 'f')
            Digit = (unsigned long) (c - 'a') + 10;
        else if (c >= 'A' && c <= 'F')
            Digit = (unsigned long) (c - 'A') + 10;
        else
            break;
        Value = (Value << 4) + Digit;
    }
    return Value;
}


int Calculate_CRC32_Example1( const char* filename, char* checksumhex )
{
    /*Generate CRC32 checksum using CalculateFile*/
    unsigned long checksum;
    if( SL_FCRC32_CalculateFile( &checksum, filename ) != 0 )
        return 0;

    /*Get the hexadecimal representation of checksum*/
    SL_FCRC_ConvertToHex32( checksumhex, checksum, 0 );

    return 1;
}

int Calculate_CRC32_Example2( const char* filename, char* checksumhex )
{
    /*Generate CRC32 checksum using Update and Final*/
    FILE* file;
    unsigned char buff[ BUFF_SIZE ];
    unsigned long checksum;
    unsigned long crc; /*crc variable*/

    file = fopen( filename, "rb" );
    if( file == NULL )
    {
        printf( "\nCould not open file: %s", filename );
        return 0;
    }

    /*Initialize crc variable before calling Update, Final*/
    SL_FCRC32_Init( &crc );

    /*Calculate the checksum by calling Update for each block of the file*/
    while( !feof( file ) )
    {
        unsigned int nCount = fread( buff, sizeof( char ), BUFF_SIZE, file );
        if( ferror( file ) )
        {
            printf( "\nAn error occurred when accessing the file: %s", filename );
            fclose( file );
            return 0;
        }
        SL_FCRC32_Update( &crc, buff, nCount );
    }

    /*Do final changes and get the checksum*/
    checksum = SL_FCRC32_Final( &crc ); /*SL_FCRC32_Final reinitializes crc variable*/

    /*Get the hexadecimal representation of checksum*/
    SL_FCRC_ConvertToHex32( checksumhex, checksum, 0 );

    fclose( file );

    return 1;
}

int Createfile(const char* filename);
int Createfile(const char* filename)
{
	int ch;
	unsigned long fsize, count=0;
	FILE *fpr, *fpw;
	fpr=fopen(filename,"rb");
	if(fpr==NULL)
	{
            printf("Failed to Open");
			return -1;
	}
	fpw=fopen("C:\\Users\\Jahagirdar\\Desktop\\final_load.hex","wb");
	if(fpw==NULL)
	{
			fclose(fpr);
            printf("Failed to Open in write mode");
			return -1;
	}

	fseek(fpr,0L,SEEK_END);
	fsize=ftell(fpr);
	printf("filesize=%lu\n", fsize);

//	fsize-=4;

	fseek(fpr,0L,SEEK_SET);
    while((!feof(fpr) && count<fsize))
	{
		if(count>=(fsize-4))
		{
	  check_crc<<=8;
	  ch = fgetc(fpr);
	  check_crc|=ch;
      count++;
	    }
		else
		{
	  ch = fgetc(fpr);
	  fputc(ch, fpw);
      count++;
		}
	}
//	printf("count=%lu\n", count);
	printf("check crc=%X\n", check_crc);
	fclose(fpr);
	fclose(fpw);
    return 0;
	

}

int main()
{
    char buff[ 256 ];
    char checksumhex[ SLC_FCRC_MAXHEXSIZE ]; /*0-terminated*/

    do
    {
        /*Get the file name from the user*/
        printf( "\nEnter a file name:\n" );
        gets( buff );
		Createfile(buff);
        /*Calculate the checksum using CalculateFile*/
        if( Calculate_CRC32_Example1( "C:\\Users\\Jahagirdar\\Desktop\\final_load.hex", checksumhex ) != 0 )
            printf( "\nCRC32 checksum calculated using CalculateFile:    %s", checksumhex );
		 //Calculate_CRC32_Example1( "C:\\Users\\Jahagirdar\\Desktop\\final_load.hex", checksumhex);
        /*Calculate the checksum using Update and Final*/
        if( Calculate_CRC32_Example2( "C:\\Users\\Jahagirdar\\Desktop\\final_load.hex", checksumhex ) != 0 )
            printf( "\nCRC32 checksum calculated using Update and Final: %s", checksumhex );
		 //Calculate_CRC32_Example2( "C:\\Users\\Jahagirdar\\Desktop\\final_load.hex", checksumhex );

		check_crc_calculate=Atohex(checksumhex);

	printf("\ncheck crc calculate=%lu %X\n", check_crc_calculate, check_crc_calculate);

		if(check_crc_calculate == check_crc)
			printf( "CRC matching\n");
		else 
			printf( "CRC not matching\n");

        /*Continue?*/
        printf( "\nContinue (Y/N)?" );
        gets( buff );
    } while ( *buff == 'y' || *buff == 'Y' );

    return 0;
}