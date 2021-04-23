#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define NKairports  322       /* number of keys */
#define NGairports  628       /* number of vertices */
#define NSairports  3       /* length of salt strings */

int Gairports[] = {0, 0, 0, 0, 0, 258, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 25, 0, 139, 0, 0, 447, 0, 0, 0, 114, 0, 0,
    565, 0, 0, 98, 347, 0, 110, 0, 0, 134, 0, 0, 0, 52, 0, 0, 0, 0, 0, 0,
    0, 0, 144, 0, 118, 0, 0, 0, 107, 0, 1, 144, 0, 0, 166, 0, 0, 0, 584, 0,
    580, 0, 70, 179, 70, 450, 536, 0, 0, 0, 0, 23, 0, 0, 552, 134, 0, 0,
    46, 0, 290, 170, 0, 0, 122, 0, 0, 159, 0, 429, 0, 93, 0, 28, 331, 0, 0,
    193, 0, 171, 158, 0, 128, 0, 45, 0, 0, 0, 272, 253, 0, 0, 0, 0, 0, 0,
    583, 540, 47, 198, 0, 196, 0, 0, 0, 0, 0, 0, 0, 133, 0, 0, 0, 0, 0,
    550, 0, 0, 54, 0, 0, 0, 34, 0, 0, 150, 47, 0, 569, 0, 499, 0, 0, 0,
    273, 0, 0, 0, 0, 273, 0, 0, 37, 268, 119, 377, 0, 0, 0, 183, 116, 606,
    0, 0, 0, 276, 32, 26, 0, 74, 0, 0, 222, 525, 0, 62, 0, 351, 611, 597,
    22, 468, 0, 259, 0, 0, 182, 0, 0, 0, 0, 136, 0, 0, 0, 0, 287, 0, 0, 0,
    0, 599, 503, 125, 379, 87, 0, 0, 0, 0, 0, 548, 381, 205, 0, 0, 0, 0, 0,
    179, 0, 0, 0, 604, 128, 0, 0, 19, 595, 0, 92, 445, 0, 0, 0, 0, 311, 47,
    212, 569, 0, 284, 0, 0, 142, 0, 0, 31, 41, 103, 0, 228, 154, 0, 82, 0,
    0, 0, 0, 115, 527, 254, 215, 0, 189, 176, 0, 84, 0, 306, 371, 72, 0,
    244, 123, 0, 0, 77, 0, 0, 35, 0, 0, 209, 59, 593, 13, 312, 0, 0, 190,
    241, 0, 0, 12, 507, 572, 140, 445, 539, 0, 0, 144, 0, 0, 380, 0, 103,
    287, 0, 0, 0, 0, 379, 596, 528, 246, 31, 11, 97, 0, 279, 289, 0, 0, 0,
    131, 487, 246, 46, 0, 73, 0, 138, 597, 0, 304, 379, 234, 94, 249, 229,
    0, 246, 392, 445, 536, 463, 0, 0, 120, 0, 585, 79, 285, 149, 49, 0, 50,
    461, 49, 131, 532, 0, 178, 0, 0, 309, 13, 0, 0, 103, 0, 594, 0, 216, 0,
    75, 22, 0, 169, 210, 91, 420, 430, 515, 258, 238, 594, 0, 0, 0, 0, 0,
    0, 121, 438, 590, 334, 218, 0, 39, 176, 90, 288, 14, 0, 229, 0, 38, 0,
    0, 253, 0, 0, 0, 492, 220, 546, 142, 238, 305, 32, 0, 8, 224, 0, 152,
    564, 610, 120, 0, 196, 0, 246, 0, 31, 476, 112, 495, 262, 500, 0, 0, 0,
    0, 617, 130, 0, 0, 165, 0, 157, 302, 13, 505, 366, 176, 380, 0, 0, 63,
    407, 114, 205, 137, 486, 0, 250, 204, 0, 0, 68, 407, 102, 0, 0, 518, 0,
    0, 0, 0, 191, 511, 0, 221, 604, 0, 0, 0, 111, 0, 162, 0, 182, 134, 96,
    184, 256, 0, 266, 0, 0, 111, 0, 267, 44, 0, 0, 604, 0, 570, 0, 0, 0,
    305, 247, 0, 0, 38, 339, 0, 409, 151, 0, 23, 488, 125, 0, 197, 0, 67,
    0, 167, 385, 248, 0, 0, 0, 156, 172, 0, 0, 0, 106, 91, 0, 0, 4, 0, 0,
    411, 0, 5, 0, 583, 0, 257, 0, 157, 33, 0, 278, 85, 93, 513, 108, 104,
    329, 0, 105, 0, 119, 488, 64, 0, 0, 557, 186, 573, 128, 106, 390, 44,
    0, 0, 19, 85, 468, 62, 117, 0, 0, 613, 0, 135, 213, 185, 196};

char *Kairports[] = {"ABE", "ABI", "ABQ", "ABR", "ABY", "ACK", "ACT", "ACV",
    "ACY", "ADK", "ADQ", "AEX", "AGS", "AKN", "ALB", "ALO", "AMA", "ANC",
    "APN", "ASE", "ATL", "ATW", "AUS", "AVL", "AVP", "AZO", "BDL", "BET",
    "BFL", "BGM", "BGR", "BHM", "BIL", "BIS", "BJI", "BLI", "BMI", "BNA",
    "BOI", "BOS", "BPT", "BQK", "BQN", "BRD", "BRO", "BRW", "BTM", "BTR",
    "BTV", "BUF", "BUR", "BWI", "BZN", "CAE", "CAK", "CDC", "CDV", "CEC",
    "CHA", "CHO", "CHS", "CID", "CIU", "CLD", "CLE", "CLL", "CLT", "CMH",
    "CMI", "CMX", "CNY", "COD", "COS", "COU", "CPR", "CRP", "CRW", "CSG",
    "CVG", "CWA", "DAB", "DAL", "DAY", "DBQ", "DCA", "DEN", "DFW", "DHN",
    "DIK", "DLG", "DLH", "DRO", "DSM", "DTW", "DVL", "EAU", "ECP", "EGE",
    "EKO", "ELM", "ELP", "ERI", "ESC", "EUG", "EVV", "EWN", "EWR", "EYW",
    "FAI", "FAR", "FAT", "FAY", "FCA", "FLG", "FLL", "FNT", "FSD", "FSM",
    "FWA", "GCC", "GCK", "GEG", "GFK", "GGG", "GJT", "GNV", "GPT", "GRB",
    "GRI", "GRK", "GRR", "GSO", "GSP", "GST", "GTF", "GTR", "GUC", "GUM",
    "HDN", "HIB", "HLN", "HNL", "HOB", "HOU", "HPN", "HRL", "HSV", "HYA",
    "HYS", "IAD", "IAG", "IAH", "ICT", "IDA", "ILG", "ILM", "IMT", "IND",
    "INL", "ISN", "ISP", "ITH", "ITO", "JAC", "JAN", "JAX", "JFK", "JLN",
    "JMS", "JNU", "KOA", "KTN", "LAN", "LAR", "LAS", "LAW", "LAX", "LBB",
    "LBE", "LCH", "LEX", "LFT", "LGA", "LGB", "LIH", "LIT", "LNK", "LRD",
    "LSE", "LWS", "MAF", "MBS", "MCI", "MCO", "MDT", "MDW", "MEI", "MEM",
    "MFE", "MFR", "MGM", "MHK", "MHT", "MIA", "MKE", "MKG", "MLB", "MLI",
    "MLU", "MMH", "MOB", "MOT", "MQT", "MRY", "MSN", "MSO", "MSP", "MSY",
    "MTJ", "MVY", "MYR", "OAJ", "OAK", "OGG", "OKC", "OMA", "OME", "ONT",
    "ORD", "ORF", "ORH", "OTH", "OTZ", "PAH", "PBG", "PBI", "PDX", "PHF",
    "PHL", "PHX", "PIA", "PIB", "PIH", "PIT", "PLN", "PNS", "PPG", "PSC",
    "PSE", "PSG", "PSP", "PUB", "PVD", "PWM", "RAP", "RDD", "RDM", "RDU",
    "RHI", "RIC", "RKS", "RNO", "ROA", "ROC", "ROW", "RST", "RSW", "SAF",
    "SAN", "SAT", "SAV", "SBA", "SBN", "SBP", "SCC", "SCE", "SDF", "SEA",
    "SFO", "SGF", "SGU", "SHV", "SIT", "SJC", "SJT", "SJU", "SLC", "SMF",
    "SMX", "SNA", "SPI", "SPS", "SRQ", "STC", "STL", "STT", "STX", "SUN",
    "SUX", "SWF", "SYR", "TLH", "TOL", "TPA", "TRI", "TTN", "TUL", "TUS",
    "TVC", "TWF", "TXK", "TYR", "TYS", "UST", "VEL", "VLD", "VPS", "WRG",
    "WYS", "XNA", "YAK", "YUM"};


/* return index of key in K if key is found, -1 otherwise */
int get_index_airports(const char *key)
{
    int f1 = 0, f2 = 0, i;

    for (i = 0; key[i] != '\0' && i < NSairports; i++) {
        f1 += "vJq"[i] * key[i];
        f2 += "Lg3"[i] * key[i];
    }
    i = (Gairports[f1 % NGairports] + Gairports[f2 % NGairports]) % NGairports;
    if (i < NKairports && strcmp(key, Kairports[i]) == 0)
        return i;

    return -1;
}
/*
int main()
{
    int i;
    char *junk[] = {"ACASSICUHAIUSCSACASCASKHCKJHSAKJCHK827349RFEWIHIWUE",
                    "abc", "x", "99"};

    for (i = 0; i < 4; i++)
        assert(get_index(junk[i]) == -1);

    for (i = 0; i < NK; i++)
        assert(get_index(K[i]) == i);

    printf("OK\n");
    return 0;
}*/
