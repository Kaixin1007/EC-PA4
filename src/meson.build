subdir('ActorGraph')



edge_files = files(['edge.hpp', 'point.hpp'])
edge_includes = include_directories('.')
edge_lib = library('edge', sources: edge_files)
edge_dep = declare_dependency(include_directories: edge_includes,
   link_with: edge_lib)   

point_files = files([ 'point.hpp', 'edge.hpp'])
point_includes = include_directories('.')
point_lib = library('point', sources: point_files)
point_dep = declare_dependency(include_directories: point_includes,
   link_with: point_lib)   


city_files = files(['city.cpp', 'city.hpp'])
city_includes = include_directories('.')
city_lib = library('city', sources: city_files,dependencies :[point_dep, edge_dep])
city_dep = declare_dependency(include_directories: city_includes,
   link_with: city_lib)

ActorGraph_lib = library('ActorGraph', sources: ActorGraph_files,dependencies :[point_dep, edge_dep,city_dep])
ActorGraph_dep = declare_dependency(include_directories: ActorGraph_includes,
   link_with: ActorGraph_lib)
   
navigationsystem_exe = executable('navigationsystem.cpp.executable', 
    sources: ['navigationsystem.cpp'],
    dependencies : [point_dep, edge_dep,ActorGraph_dep,city_dep,cxxopts_dep],
    install : true)