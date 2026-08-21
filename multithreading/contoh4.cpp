#include <iostream>                                                                                                  
   #include <thread>                                                                                                    
   #include <vector>                                                                                                    
   #include <mutex>                                                                                                     
   #include <future>                                                                                                    
   #include <chrono>                                                                                                    
   #include <utility> // Untuk std::move                                                                                
                                                                                                                        
   // 1. DEFINISI STRUCT: Data yang diolah oleh sistem Tycoon                                                           
   struct GameResource {                                                                                                
       int id;                                                                                                          
       int value;                                                                                                       
       std::string type;                                                                                                
                                                                                                                        
       // Fungsi untuk representasi string (lebih mudah debugging)                                                      
       friend std::ostream& operator<<(std::ostream& os, const GameResource& res) {                                     
           return os << "Resource ID: " << res.id << ", Value: " << res.value << ", Type: " << res.type;                
       }                                                                                                                
   };                                                                                                                   
                                                                                                                        
   // Global mutex untuk melindungi akses ke console (data bersama)                                                     
   std::mutex mtx;                                                                                                      
                                                                                                                        
   // Fungsi worker yang mensimulasikan tugas menggunakan struct (Membutuhkan Mutex)                                    
   void worker(GameResource resource) {                                                                                 
       // Bagian kritis yang harus dilindungi oleh mutex                                                                
       {                                                                                                                
           std::lock_guard<std::mutex> lock(mtx);                                                                       
           std::cout << "[System] Worker thread " << resource.id << " memulai tugas. Memproses: " << resource << "\n";  
       }                                                                                                                
                                                                                                                        
       // Simulasi pekerjaan selama durasi yang ditentukan (Chronos)                                                    
       // Kita gunakan auto untuk variabel durasi                                                                       
       auto delay = std::chrono::milliseconds(500 * resource.id);                                                       
       std::this_thread::sleep_for(delay);                                                                              
                                                                                                                        
       // Bagian kritis berikutnya                                                                                      
       {                                                                                                                
           std::lock_guard<std::mutex> lock(mtx);                                                                       
           std::cout << "[System] Worker thread " << resource.id << " selesai bekerja. Sumber daya diproses.\n";        
       }                                                                                                                
   }                                                                                                                    
                                                                                                                        
   // Fungsi worker yang juga menggunakan nilai kembali (return value)                                                  
   // Mengambil GameResource sebagai input                                                                              
   GameResource process_resources(GameResource resource) {                                                              
       // Simulasi pemrosesan sumber daya                                                                               
       std::this_thread::sleep_for(std::chrono::milliseconds(250));                                                     
                                                                                                                        
       // Modifikasi resource saat diproses                                                                             
       resource.value += 50;                                                                                            
                                                                                                                        
       std::cout << "[System] Thread Resource " << resource.id << " berhasil melalui pipeline (Returning upgraded       
 data).\n";                                                                                                             
       return resource; // Nilai yang akan dikembalikan                                                                 
   }                                                                                                                    
                                                                                                                        
                                                                                                                        
   int main() {                                                                                                         
       std::cout << "=============================================\n";                                                  
       std::cout << "=== SIMULASI GAME TYCOON (MULTITHREADING) ===\n";                                                  
       std::cout << "=============================================\n";                                                  
                                                                                                                        
       // 1. Demonstrasi std::async dan std::future (Menunggu Nilai Kembali)                                            
       std::cout << "\n--- BAGIAN 1: Asynchronous (Mengambil Nilai melalui Future) ---\n";                              
       std::vector<std::future<GameResource>> futures;                                                                  
                                                                                                                        
       // Persiapan data sumber daya                                                                                    
       std::vector<GameResource> initial_resources;                                                                     
       for (int i = 1; i <= 3; ++i) {                                                                                   
           initial_resources.push_back({i, i * 10, "Minerals"});                                                        
       }                                                                                                                
                                                                                                                        
       // Meluncurkan 3 tugas pemrosesan sumber daya secara bersamaan                                                   
       for (auto& resource : initial_resources) { // Menggunakan auto& untuk iterasi                                    
           // std::async meluncurkan task dan mengembalikan std::future                                                 
           futures.push_back(std::async(std::launch::async, process_resources, resource));                              
       }                                                                                                                
                                                                                                                        
       GameResource total_resource = {0, 0, "TOTAL"};                                                                   
       // Menunggu dan mengambil hasil dari setiap future                                                               
       for (auto& ftr : futures) { // Menggunakan auto& untuk iterator                                                  
           // ftr.get() akan MEMBLOKIR program hingga hasil tersedia                                                    
           GameResource result = ftr.get();                                                                             
                                                                                                                        
           // Memproses hasil yang didapat                                                                              
           total_resource.value += result.value;                                                                        
           std::cout << "[MAIN] ✔️ Berhasil mengambil hasil. Data terbaru: " << result << "\n";                         
       }                                                                                                                
       std::cout << "\n[MAIN] ✨ Ringkasan Sumber Daya Akhir: " << total_resource << "\n";                              
                                                                                                                        
                                                                                                                        
       // 2. Demonstrasi std::thread dan std::mutex (Operasi Bersamaan Tanpa Nilai Kembali)                             
       std::cout << "\n\n--- BAGIAN 2: Concurrent (Memastikan Keamanan Data dengan Mutex) ---\n";                       
                                                                                                                        
       // Kita akan meluncurkan 5 worker thread                                                                         
       std::vector<std::thread> threads;                                                                                
                                                                                                                        
       // Membuat data resource untuk worker thread                                                                     
       for (auto i = 1; i < 6; ++i) {                                                                                   
           GameResource resource_data = {i, i * 100, "Job"};                                                            
           // Membuat thread baru dan menjalankan fungsi worker                                                         
           threads.emplace_back(worker, resource_data);                                                                 
       }                                                                                                                
                                                                                                                        
       // Tunggu semua thread selesai (Join)                                                                            
       for (auto& t : threads) {                                                                                        
           t.join(); // join() membuat main thread menunggu thread ini selesai                                          
       }                                                                                                                
                                                                                                                        
       std::cout << "\n=============================================\n";                                                
       std::cout << "✅ Simulasi sukses! Semua sistem Tycoon bekerja secara paralel dan aman.\n";                       
       return 0;                                                                                                        
   }