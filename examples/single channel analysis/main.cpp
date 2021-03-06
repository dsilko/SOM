/* Copyright 2018 Denis Silko. All rights reserved.
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 http:www.apache.org/licenses/LICENSE-2.0
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#include "som.hpp"
#include "som_cv_view.hpp"

using namespace cv;
using namespace som;
using namespace std;

static const string THREE_CHANNEL_MAPS_WINDOW_NAME = "Three-channel map";
static const string SINGLE_CHANNEL_MAPS_WINDOW_NAME = "Single channel maps";

int main(int argc, const char * argv[]) {
    
    // BGR colors
    vector<float> red      {0.00, 0.0, 1.00},
                  green    {0.0,  1.0, 0.00},
                  blue     {1.00, 0.0, 0.00},
                  yellow   {0.20, 1.0, 1.00},
                  orange   {0.25, 0.4, 1.00},
                  purple   {1.0,  0.0, 1.00},
                  dk_green {0.25, 0.5, 0.00},
                  dk_blue  {0.50, 0.0, 0.00};
    
    vector<vector<float>> data{red, green, blue, yellow, orange, purple, dk_green, dk_blue};
    
    const auto radius = 60;
    const auto hexSize = 3;
    const auto channels = 3;
    const auto learningRate = 0.1;
    const auto epochs = 5000;
    
    SOM som(CPU);
    som.create(radius, hexSize, channels);
    som.prepare(data, MINMAX_BY_COLUMNS, RANDOM_FROM_DATA);
    som.train(epochs, learningRate);
    
    // Draw single channel maps
    vector<Mat> singleChannelMaps {
        drawSingleChannelMap(som, 0, ColormapConfiguration(COLORSCALE_PARULA)),
        drawSingleChannelMap(som, 1, ColormapConfiguration(COLORSCALE_PARULA)),
        drawSingleChannelMap(som, 2, ColormapConfiguration(COLORSCALE_PARULA))
    };
    
    // Concatenate maps
    Mat allMaps;
    hconcat(singleChannelMaps, allMaps);
    
    // Draw and show single channel maps
    namedWindow(SINGLE_CHANNEL_MAPS_WINDOW_NAME);
    moveWindow(SINGLE_CHANNEL_MAPS_WINDOW_NAME, 90, 100);
    imshow(SINGLE_CHANNEL_MAPS_WINDOW_NAME, allMaps);
    
    // Draw and show three-channel map
    namedWindow(THREE_CHANNEL_MAPS_WINDOW_NAME);
    moveWindow(THREE_CHANNEL_MAPS_WINDOW_NAME, 600, 20);
    imshow(THREE_CHANNEL_MAPS_WINDOW_NAME, draw3DMap(som));

    waitKey();
    
    cv::destroyAllWindows();
    
    return 0;
}
