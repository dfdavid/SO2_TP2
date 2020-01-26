#include <stdio.h>
#include <stdlib.h>
#include <netcdf.h>
#include <fcntl.h>


#define NX 21696
#define NY 21696
#define NKERNEL 3

#define ARCHIVO "../includes/OR_ABI-L2-CMIPF-M6C02_G16_s20191011800206_e20191011809514_c20191011809591.nc"

int main() {

    /*
     * http://cortesfernando.blogspot.com/2011/10/malloc-vs-calloc.html
     */
    float *dato_saliente=(float*)calloc((NX-NKERNEL+1) * (NY-NKERNEL+1), sizeof(float));
    float *data_in= (float*)calloc(NX*NY, sizeof(float));
    float kernel [NKERNEL][NKERNEL]={{-1. -1, -1},
                                     {-1,  8, -1},
                                     {-1. -1, -1}};
    int nc_id, var_id, ret_value;
    size_t inicio[2]={0};
    size_t cuenta[2]={0};

    cuenta[0]=NX;
    cuenta[1]=NY;

    inicio[0]=0;
    inicio[1]=0;

    printf("leyendo archivo NC a memoria\n");
    /*
    https://www.unidata.ucar.edu/software/netcdf/docs/group__datasets.html#gaccbdb128a1640e204831256dbbc24d3e

    int nc_open 	(const char *path, int omode, int *ncidp)

    Open an existing netCDF file.

            This function opens an existing netCDF dataset for access. It determines the underlying file format automatically. Use the same call to open a netCDF classic or netCDF-4 file.

            Parameters
    path	File name for netCDF dataset to be opened. When the dataset is located on some remote server, then the path may be an OPeNDAP URL rather than a file path.
            omode	The open mode flag may include NC_WRITE (for read/write access) and NC_SHARE (see below) and NC_DISKLESS (see below).
    ncidp	Pointer to location where returned netCDF ID is to be stored.

            Open Mode

    A zero value (or NC_NOWRITE) specifies the default behavior: open the dataset with read-only access, buffering and caching accesses for efficiency.



    Here is an example using nc_open()to open an existing netCDF dataset named foo.nc for read-only, non-shared access:

     #include <netcdf.h>
    ...
    int status = NC_NOERR;
    int ncid;
    ...
    status = nc_open("foo.nc", 0, &ncid);
    if (status != NC_NOERR) handle_error(status);

    Author
    Glenn Davis, Ed Hartnett, Dennis Heimbigner

    Definition at line 635 of file dfile.c
    */
    (ret_value= nc_open(ARCHIVO, 0, &nc_id) );

    if( )

        return 0;
}

