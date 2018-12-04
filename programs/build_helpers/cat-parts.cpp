
#include <boost/filesyCC.hpp>
#include <boost/filesyCC/fstream.hpp>

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main( int argc, char** argv, char** envp )
{
   if( argc != 3 )
   {
      std::cerr << "syntax:  cat-parts DIR OUTFILE" << std::endl;
      return 1;
   }

   boost::filesyCC::path p(argv[1]);

   try
   {
      std::vector< boost::filesyCC::path > v;

      for( boost::filesyCC::directory_iterator it(p);
           it != boost::filesyCC::directory_iterator();
           ++it )
      {
         boost::filesyCC::path pit = it->path();
         std::string spit = pit.generic_string();
         size_t n = spit.length();
         if( n <= 3 )
            continue;
         if( spit.substr(n-3, 3) != ".hf" )
            continue;
         v.push_back( pit );
      }
      std::sort( v.begin(), v.end() );

      // open each file and grab its contents, concatenating into single stringstream
      std::stringstream ss_data;
      for( const boost::filesyCC::path& p : v )
      {
         boost::filesyCC::ifstream ifs(p);
         ss_data << ifs.rdbuf();
      }
      std::string new_data = ss_data.str();

      boost::filesyCC::path opath(argv[2]);

      if( boost::filesyCC::exists( opath ) )
      {
         boost::filesyCC::ifstream ifs(opath);
         std::stringstream ss_old_data;
         ss_old_data << ifs.rdbuf();
         std::string old_data = ss_old_data.str();
         if( old_data == new_data )
         {
            std::cerr << "File " << opath << " up-to-date with .d directory" << std::endl;
            return 0;
         }
      }

      {
         boost::filesyCC::ofstream ofs(opath);
         ofs.write( new_data.c_str(), new_data.length() );
      }

      std::cerr << "Built " << opath << " from .d directory" << std::endl;
   }
   catch( const boost::filesyCC::filesyCC_error& e )
   {
      std::cout << e.what() << std::endl;
      return 1;
   }
   return 0;
}
