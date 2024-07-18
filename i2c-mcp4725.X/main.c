#include "system.h"
#include "i2c.h"
#include <libpic30.h>

#define size_signal 481
uint8_t dac_data[2];

uint16_t sine_signal[size_signal]    __attribute__ ((space(auto_psv))) = {2101,2295,2052,2246,2440,2197,2390,2584,2340,2533,2725,2481,2672,2864,2618,2809,2999,2752,2941,3129,2880,3067,3254,3003,3188,3372,3119,3302,3484,3228,3409,3588,3330,3507,3684,3422,3597,3770,3506,3678,3848,3580,3749,3916,3645,3809,3973,3698,3860,4019,3741,3899,4055,3774,3927,4080,3794,3944,4093,3804,3950,4095,3802,3944,4086,3789,3927,4065,3764,3899,4033,3728,3860,3990,3682,3809,3936,3624,3749,3872,3557,3678,3797,3479,3597,3714,3392,3507,3621,3297,3409,3519,3193,3302,3410,3081,3188,3294,2963,3067,3171,2838,2941,3043,2708,2809,2909,2573,2672,2772,2434,2533,2631,2292,2390,2488,2149,2246,2343,2004,2101,2198,1859,1956,2053,1714,1812,1910,1571,1669,1768,1430,1530,1629,1293,1394,1495,1160,1262,1364,1031,1135,1240,908,1014,1121,792,900,1009,683,794,905,581,695,810,489,605,723,405,525,645,331,454,578,266,393,521,213,343,474,170,303,438,138,275,414,117,258,400,107,252,398,109,258,408,122,275,429,147,303,461,183,343,504,229,393,558,287,454,622,354,525,696,432,605,780,519,695,873,614,794,974,718,900,1083,830,1014,1199,949,1135,1322,1073,1262,1451,1203,1394,1584,1338,1530,1722,1477,1669,1862,1619,1812,2005,1762,1956,2150,1907,2101,2295,2052,2246,2440,2197,2390,2584,2340,2533,2725,2481,2672,2864,2618,2809,2999,2752,2941,3129,2880,3067,3254,3003,3188,3372,3119,3302,3484,3228,3409,3588,3330,3507,3684,3422,3597,3770,3506,3678,3848,3580,3749,3916,3645,3809,3973,3698,3860,4019,3741,3899,4055,3774,3927,4080,3794,3944,4093,3804,3950,4095,3802,3944,4086,3789,3927,4065,3764,3899,4033,3728,3860,3990,3682,3809,3936,3624,3749,3872,3557,3678,3797,3479,3597,3714,3392,3507,3621,3297,3409,3519,3193,3302,3410,3081,3188,3294,2963,3067,3171,2838,2941,3043,2708,2809,2909,2573,2672,2772,2434,2533,2631,2292,2390,2488,2149,2246,2343,2004,2101,2198,1859,1956,2053,1714,1812,1910,1571,1669,1768,1430,1530,1629,1293,1394,1495,1160,1262,1364,1031,1135,1240,908,1014,1121,792,900,1009,683,794,905,581,695,810,489,605,723,405,525,645,331,454,578,266,393,521,213,343,474,170,303,438,138,275,414,117,258,400,107,252,398,109,258,408,122,275,429,147,303,461,183,343,504,229,393,558,287,454,622,354,525,696,432,605,780,519,695,873,614,794,974,718,900,1083,830,1014,1199,949,1135,1322,1073,1262,1451,1203,1394,1584,1338,1530,1722,1477,1669,1862,1619,1812,2005,1762,1956,2150,1907,2101};
uint16_t sawtooth_wave[size_signal]  __attribute__ ((space(auto_psv))) = {3964,4095,3787,3918,4049,3741,3872,4002,3695,3825,3956,3648,3779,3909,3602,3732,3863,3555,3686,3817,3509,3640,3770,3463,3593,3724,3416,3547,3677,3370,3500,3631,3323,3454,3585,3277,3408,3538,3231,3361,3492,3184,3315,3446,3138,3268,3399,3091,3222,3353,3045,3176,3306,2999,3129,3260,2952,3083,3214,2906,3037,3167,2860,2990,3121,2813,2944,3074,2767,2897,3028,2720,2851,2982,2674,2805,2935,2628,2758,2889,2581,2712,2842,2535,2665,2796,2488,2619,2750,2442,2573,2703,2396,2526,2657,2349,2480,2610,2303,2433,2564,2256,2387,2518,2210,2341,2471,2164,2294,2425,2117,2248,2379,2071,2201,2332,2024,2155,2286,1978,2109,2239,1932,2062,2193,1885,2016,2147,1839,1970,2100,1793,1923,2054,1746,1877,2007,1700,1830,1961,1653,1784,1915,1607,1738,1868,1561,1691,1822,1514,1645,1775,1468,1598,1729,1421,1552,1683,1375,1506,1636,1329,1459,1590,1282,1413,1543,1236,1366,1497,1189,1320,1451,1143,1274,1404,1097,1227,1358,1050,1181,1312,1004,1134,1265,957,1088,1219,911,1042,1172,865,995,1126,818,949,1080,772,903,1033,726,856,987,679,810,940,633,763,894,586,717,848,540,671,801,494,624,755,447,578,708,401,531,662,354,485,616,308,439,569,262,392,523,215,346,476,169,299,430,122,3964,4095,3787,3918,4049,3741,3872,4002,3695,3825,3956,3648,3779,3909,3602,3732,3863,3555,3686,3817,3509,3640,3770,3463,3593,3724,3416,3547,3677,3370,3500,3631,3323,3454,3585,3277,3408,3538,3231,3361,3492,3184,3315,3446,3138,3268,3399,3091,3222,3353,3045,3176,3306,2999,3129,3260,2952,3083,3214,2906,3037,3167,2860,2990,3121,2813,2944,3074,2767,2897,3028,2720,2851,2982,2674,2805,2935,2628,2758,2889,2581,2712,2842,2535,2665,2796,2488,2619,2750,2442,2573,2703,2396,2526,2657,2349,2480,2610,2303,2433,2564,2256,2387,2518,2210,2341,2471,2164,2294,2425,2117,2248,2379,2071,2201,2332,2024,2155,2286,1978,2109,2239,1932,2062,2193,1885,2016,2147,1839,1970,2100,1793,1923,2054,1746,1877,2007,1700,1830,1961,1653,1784,1915,1607,1738,1868,1561,1691,1822,1514,1645,1775,1468,1598,1729,1421,1552,1683,1375,1506,1636,1329,1459,1590,1282,1413,1543,1236,1366,1497,1189,1320,1451,1143,1274,1404,1097,1227,1358,1050,1181,1312,1004,1134,1265,957,1088,1219,911,1042,1172,865,995,1126,818,949,1080,772,903,1033,726,856,987,679,810,940,633,763,894,586,717,848,540,671,801,494,624,755,447,578,708,401,531,662,354,485,616,308,439,569,262,392,523,215,346,476,169,299,430,122,3964};
uint16_t square_wave[size_signal]    __attribute__ ((space(auto_psv))) = {252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,252,398,107,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,3949,4095,3804,252};

/**
 * uint16_t sine_signal[481] __attribute__ ((space(auto_psv)))={2,5,8,5,9};
 * @return 
 */
int main()
{
    uint8_t i;
    I2C1_Init(100);
     
    while (1) 
    {
        for (i = 0; i < size_signal; i++) 
        {
            dac_data[0] = square_wave[i] >> 8 & 0x0F;
            dac_data[1] = square_wave[i]      & 0xFF;
            
            I2C1_Start();
            I2C1_Write_Addr_Slave(0xC0,I2C_Write);
            I2C1_Write_Data(dac_data[0]);
            I2C1_Write_Data(dac_data[1]);
            I2C1_Stop();
            __delay_ms(5);
        }

    }
    return 0;
}
