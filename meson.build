project('Game', 'cpp')

sdl2_dep = dependency('sdl2', required: true)
sdl2_ttf_dep = dependency('SDL2_ttf', required: true) 


inc = include_directories('lib/')

files = files('lib/AppClass.cpp', 'lib/GameStateClass.cpp', 'lib/RendererClass.cpp', 'lib/KeyboardHandler.cpp',
             'lib/Ball.cpp', 'lib/Racket.cpp', 'lib/ScoreboardRect.cpp', 'lib/RacketRect.cpp',
             'lib/BallRect.cpp', 'lib/Middleline.cpp', 'lib/Startscreen.cpp')
lib = library('library', files, dependencies: [sdl2_dep, sdl2_ttf_dep], include_directories: inc)

executable('game', 'main.cpp',
    dependencies: [sdl2_dep, sdl2_ttf_dep],
    link_with: lib,
    include_directories: inc
)
