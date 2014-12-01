// 16x16 matrix
/*
           //0  1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9  
static uint32_t flagFieldArray[][20] = {
            {b, b, b, b, b, b, b, b, w, b, b, b, b, b, b, b, w, b, b, b},
            {b, b, b, b, b, b, b, b, w, w, b, b, b, b, w, w, w, b, b, b},
            {b, b, b, b, b, b, b, b, w, w, w, b, w, w, w, w, b, b, b, b},
            {b, b, b, b, b, b, b, b, w, w, w, w, w, w, w, w, b, b, b, b},
            {b, b, b, b, b, b, b, w, w, w, w, w, w, w, w, b, b, b, b, b},
            {b, b, b, b, b, w, w, w, w, w, w, w, w, w, w, b, b, b, b, b},
            {b, b, b, w, w, w, w, w, w, w, w, w, w, w, b, b, b, b, b, b},
            {b, b, b, w, w, w, w, w, w, w, w, w, w, w, b, b, b, b, b, b},
            {b, b, b, b, b, w, w, w, w, w, w, w, w, w, w, b, b, b, b, b},
            {b, b, b, b, b, b, b, w, w, w, w, w, w, w, w, b, b, b, b, b},
            {b, b, b, b, b, b, b, b, w, w, w, w, w, w, w, w, b, b, b, b},
            {b, b, b, b, b, b, b, b, w, w, w, b, w, w, w, w, b, b, b, b},
            {b, b, b, b, b, b, b, b, w, w, b, b, b, b, w, w, w, b, b, b},
            {b, b, b, b, b, b, b, b, w, b, b, b, b, b, b, b, w, b, b, b},
            {b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b},
            {b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b}
            
  };
  
  */
  
/*
            {__BLUE, __BLUE, __BLUE, __WHITE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __WHITE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE},
            {__BLUE, __BLUE, __BLUE, __WHITE, __WHITE, __WHITE, __BLUE, __BLUE, __BLUE, __BLUE, __WHITE, __WHITE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE},
            {__BLUE, __BLUE, __BLUE, __BLUE, __WHITE, __WHITE, __WHITE, __WHITE, __BLUE, __WHITE, __WHITE, __WHITE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE},
            {__BLUE, __BLUE, __BLUE, __BLUE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE},
            {__BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE},
            {__BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE},
            {__BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __BLUE, __BLUE, __BLUE},
            {__BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __BLUE, __BLUE, __BLUE},
            {__BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE},
            {__BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE},
            {__BLUE, __BLUE, __BLUE, __BLUE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __WHITE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE},
            {__BLUE, __BLUE, __BLUE, __BLUE, __WHITE, __WHITE, __WHITE, __WHITE, __BLUE, __WHITE, __WHITE, __WHITE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE},
            {__BLUE, __BLUE, __BLUE, __WHITE, __WHITE, __WHITE, __BLUE, __BLUE, __BLUE, __BLUE, __WHITE, __WHITE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE},
            {__BLUE, __BLUE, __BLUE, __WHITE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __WHITE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE},
            {__BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE},
            {__BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE, __BLUE}
*/

 
 
 
 