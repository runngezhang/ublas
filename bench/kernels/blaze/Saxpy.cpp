/*
 saxpy kernel
*/

namespace blaze {
    
double saxpy(size_t N, size_t iterations = 1) {
    
    blaze::CompressedMatrix<double> a(N, N), b(N, N);
    double c = 3;
    
    sminit(a.rows(), a);
    sminit(b.rows(), b);
    
    std::vector<double> times;
    for(size_t i = 0; i < iterations; ++i){
        
        auto start = std::chrono::steady_clock::now();
        a += b * c;
        auto end = std::chrono::steady_clock::now();
        
        auto diff = end - start;
        times.push_back(std::chrono::duration<double, std::milli> (diff).count()); //save time in ms for each iteration
    }
    
    double tmin = *(std::min_element(times.begin(), times.end()));
    double tavg = average_time(times);
    
    // check to see if anything happened during run to invalidate the times
    if(variance(tavg, times) > max_variance){
        std::cerr << "blaze kernel 'saxpy': Time deviation too large!!!" << std::endl;
    }
    
    return tavg;
    
}

}