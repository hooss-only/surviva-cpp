target_sources(surviva PRIVATE
  main.cpp
  cursor.cpp
  game_status.cpp
  sprite.cpp
  scene.cpp
  item.cpp
)

add_subdirectory(assets)
add_subdirectory(sprites)
add_subdirectory(scenes)
add_subdirectory(items)
add_subdirectory(components)
add_subdirectory(behaviors)
add_subdirectory(math)
