/* pensar como podriamos 
lista de datos estadisticas de listas de datos
q tipo de operaciones de filtrado puedo hacer sobre esa lista de numeros
de como filtrar esa informacion  
            los q mas cmbiaron 
            rangos de datos 
            excluciones 
            TRESHOLDS
                limite rango de valores 
                    filtra info numerica
                valores q no cambuan
                valores q cambian
                excluir datos como: rewards, steeps
                    filtrar solo los pares soperiores a 20                    
                
            CUANDO CONSTRUYAMOS EL AGENTE Q INFO DE LA RAM INTERESA
                genereica
               arbol de expresiones dada una info se filtra
                        /tiempo durante los primeros 10 segundos tods lo numeros mayores se filtre
                        o deoues de 10 segundos
                        quiero este agente q utilize estos filtros al momento de entrenar                        -
                        -ibrido scrips  en python para recivir la orden desde c++ dame un observation 
                            y el c++ lo procesa
                            cambio acer el agente en c++
                                con codigo embebido python q interactue con tensorflow y openai
                                                    todo este codigo de python en tiempo de ejecucion 
                                                    se tiene q llamar  a estos scrips de python o usar la api de python para c++
                                                        python para recivir la orden desde c++ dame un observation 
                                                        y el c++ lo procesa la informacion y le da otra ves al python para 
                                                        que le de an tensorflow */


FILTRAR POR:

    //1.-FILTER_BY_COLUMNS
    2.-FILTER_EXCLUDE_CONSTANTS//MAU
    3.-FILTER_BY_VALUE//DAV
    4.-FILTER_BY_RANGES_VALUES//CIN
    //5.-FILTER_TOP_CHANGE_COLUMNS
    //6.-FILTER_TIMES_COLUMN_CHANGE_VALUE
    //7.-POR RANGO DE TIEMPO()
    8.-FILTRAR POR PARES E IMPARES//JHO
    9.-DATOS QUE MAS CAMBIAN(MAYOR 3 VECES)//FAB
    //10.-POR PORCENTAJES DE TIEMPO
    11.-bandera de cuantas veces cambian

    EXCLUIR DATOS COMO: REWARDS, STEEPS
    FILTRAR SOLO LOS PARES SOPERIORES A 20        
    
    

    revisar pipe line

    crear un wraper
        filtrar datos con tensor flow

    pasar por lo filtros y pasar a 

    #include "opencv2/imgproc/imgproc.hpp"
    #include "opencv2/highgui/highgui.hpp"
    #include <stdlib.h>
    #include <stdio.h>
    
    using namespace cv;
    
    /// Global variables
    
    int threshold_value = 0;
    int threshold_type = 3;;
    int const max_value = 255;
    int const max_type = 4;
    int const max_BINARY_value = 255;
    
    Mat src, src_gray, dst;
    char* window_name = "Threshold Demo";
    
    char* trackbar_type = "Type: \n 0: Binary \n 1: Binary Inverted \n 2: Truncate \n 3: To Zero \n 4: To Zero Inverted";
    char* trackbar_value = "Value";
    
    /// Function headers
    void Threshold_Demo( int, void* );
    
    /**
     * @function main
     */
    int main( int argc, char** argv )
    {
      /// Load an image
      src = imread( argv[1], 1 );
    
      /// Convert the image to Gray
      cvtColor( src, src_gray, CV_BGR2GRAY );
    
      /// Create a window to display results
      namedWindow( window_name, CV_WINDOW_AUTOSIZE );
    
      /// Create Trackbar to choose type of Threshold
      createTrackbar( trackbar_type,
                      window_name, &threshold_type,
                      max_type, Threshold_Demo );
    
      createTrackbar( trackbar_value,
                      window_name, &threshold_value,
                      max_value, Threshold_Demo );
    
      /// Call the function to initialize
      Threshold_Demo( 0, 0 );
    
      /// Wait until user finishes program
      while(true)
      {
        int c;
        c = waitKey( 20 );
        if( (char)c == 27 )
          { break; }
       }
    
    }
    
    
    /**
     * @function Threshold_Demo
     */
    void Threshold_Demo( int, void* )
    {
      /* 0: Binary
         1: Binary Inverted
         2: Threshold Truncated
         3: Threshold to Zero
         4: Threshold to Zero Inverted
       */
    
      threshold( src_gray, dst, threshold_value, max_BINARY_value,threshold_type );
    
      imshow( window_name, dst );