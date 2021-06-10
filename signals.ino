
int ecg_100Hz [600]={
402,386,386,382,379,397,396,416,431,442,
470,481,514,530,535,553,546,556,552,541,
545,524,520,505,487,488,466,467,459,449,
457,443,453,450,444,456,443,454,452,450,
464,454,466,466,464,477,468,480,480,477,
489,479,491,487,483,493,484,498,499,498,
516,513,544,578,627,700,751,816,854,871,
887,863,846,802,749,705,638,593,542,495,
470,431,422,408,396,404,395,413,418,424,
447,449,475,486,496,518,515,534,533,530,
537,519,522,509,492,489,464,462,447,435,
440,424,431,426,424,434,423,436,435,435,
448,440,456,456,456,469,460,474,470,469,
480,468,478,474,473,482,474,488,485,484,
495,484,496,493,493,511,519,569,624,692,
772,823,886,913,922,925,889,863,808,752,
704,638,599,550,512,493,459,454,435,425,
431,420,436,438,447,468,471,498,506,516,
535,530,546,539,534,537,517,520,503,490,
486,463,465,451,443,447,431,444,438,438,
448,438,452,448,450,460,449,463,457,458,
468,459,474,473,474,483,472,483,477,474,
482,469,481,475,474,482,469,481,473,472,
481,473,497,512,553,621,680,760,811,852,
884,877,878,843,802,759,693,652,593,544,
510,465,451,422,408,405,390,402,398,405,
422,421,447,451,465,486,488,512,514,522,
534,525,534,519,510,505,481,483,463,454,
454,438,448,438,440,446,434,445,435,434,
441,431,446,440,445,458,451,468,463,468,
473,463,475,466,466,473,463,476,468,470,
478,468,482,474,476,483,472,486,477,479,
483,472,484,475,478,486,476,490,481,483,
489,477,489,479,480,484,473,488,480,486,
499,506,554,603,676,757,814,877,898,908,
901,858,827,761,702,642,570,525,467,428,
402,369,369,352,353,364,362,388,392,411,
435,444,477,486,506,524,524,543,534,532,
531,511,513,491,483,475,454,456,437,433,
430,415,425,413,417,422,415,433,427,433,
442,435,452,445,452,461,455,474,469,476,
480,471,483,471,472,475,465,478,468,471,
475,465,478,468,472,475,465,477,467,472,
475,468,483,475,484,495,505,556,606,685,
763,817,876,892,901,887,842,805,736,677,
616,550,512,460,431,411,387,391,376,379,
384,378,397,396,412,428,433,461,465,482,
497,499,519,512,518,519,505,510,490,485,
478,458,461,444,440,438,426,437,424,428,
431,423,438,430,438,445,440,457,451,460,
466,460,476,468,475,480,474,488,479,484,
486,476,487,475,479,482,473,486,477,484,
486,478,490,478,484,485,477,490,480,488,
490,483,499,498,531,583,644,730,790,850,
887,891,895,855,818,765,698,649,578,529,
482,433,417,388,386,385,379,396,391,404,
414,415,437,438,458,474,479,505,505,520,
526,519,529,513,513,505,488,490,468,464,
458,442,447,428,430,428,418,431,422,432,
437,432,448,440,449,452,447,464,457,470,
};

//filtro pasa bajos 100Hz
int Impulse_response[293]={
  71,
  1483,
  2327,
  668,
  -918,
  -45,
  575,
  - 294,
  -227,
  377,
  -94,
  -233,
  259,
  -12,
  -212,
  188,
  26,
  -189,
  142,
  46,
  -170,
  111,
  56,
  -155,
  90,
  63,
  -143,
  74,
  66,
  -133,
  63,
  69,
  -127,
  54,
  71,
  -122,
  47,
  74 ,
  -118,
  41,
  76,
  -115,
  36,
  79,
  -113,
  32,
  82,
  -112,
  27,
  85,
  -111,
  23,
  89,
  -111,
  20,
  92,
  -111,
  15,
  97,
  -112,
  12,
  102,
  -112,
  8,
  108,
  -114,
  3,
  114,
  -115,
  -2,
  120,
  -117,
  -8,
  127,
  -118,
  -13,
  134,
  -119,
  -20,
  142,
  -121 ,
  -26,
  151,
  -122,
  -34,
  160,
  -124,
  -42,
  170,
  -126,
  -51,
  182,
  -128,
  -62,
  194,
  -129,
  -73,
  208,
  -131,
  - 86,
  223,
  -132,
  -101,
  239,
  -133,
  -118,
  258,
  -135,
  -136,
  279,
  -136,
  -159,
  304,
  -138,
  -186,
  331,
  -140,
  -218,
  366,
  -139,
  -254,
  410,
  -139,
  -302 ,
  460,
  -142,
  -362,
  530,   -141
  ,
-446,
  620,
  -142,
  -561,
  755,
  -142,
  -741,
  965,
  -142,
  -1050,
  1355,
  -144,
  -1730,
  2327 ,
  -143,
  -4444,
  9104,
  21703,
  9104,
  -4444,
  -143,
  2327,
  -1730,
  -144,
  1355,
  -1050,
  -142,
  965,
  -741,
  -142,
  755,
  -561,
  -142,
  620,
  -446, -141
  ,
  530,
  -362 ,
  -142,
  460,
  -302,
  -139,
  410,
  -254,
  -139,
  366,
  -218,
  -140,
  331,
  -186,
  -138,
  304,
  -159,
  -136,
  279,
  -136,
  - 135,
  258,
  -118,
  -133,
  239,
  -101,
  -132,
  223,
  -86,
  -131,
  208,
  -73,
  -129,
  194,
  -62,
  -128,
  182,
  -51,
  -126,
  170,
  -42,
  -124,
  160,
  -34,
  -122 ,
  151,
  -26,
  -121,
  142,
  -20,
  -119,
  134,
  -13,
  -118,
  127,
  -8,
  -117,
  120,
  -2,
  -115,
  114,
  3,
  -114,
  108,
  8,
  -112,
  102,
  12,
  -112,
  97,
  15,
  -111,
  92,
  20,
  -111,
  89,
  23,
  -111,
  85,
  27,
  -112,
  82,
  32,
  -113,
  79,
  36,
  -115,
  76,
  41,
  -118,
  74,
  47 ,
  -122,
  71,
  54,
  -127,
  69,
  63,
  -133,
  66,
  74,
  -143,
  63,
  90,
  -155,
  56,
  111,
  -170,
  46,
  142,
  -189,
  26,
  188,
  -212,
  -12,
  259,
  -233,
  -94,
  377,
  -227,
  -294,
  575,
  -45,
  -918,
  668,
  2327,
  1483,
  71
};