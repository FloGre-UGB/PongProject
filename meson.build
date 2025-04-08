project('Game', 'cpp')

sdl2_dep = dependency('sdl2', required: true)
inc = include_directories('lib/')

files =files('lib/AppClass.cpp', 'lib/GameStateClass.cpp', 'lib/RendererClass.cpp')
lib = library('library', files, dependencies: [sdl2_dep], include_directories: inc)

executable('game', 'main.cpp',
    dependencies: [sdl2_dep],
    link_with: lib,
    include_directories: inc
)
