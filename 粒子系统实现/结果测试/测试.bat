ParticleSystems.exe -input system9_01_hose.txt -refresh 0.1  -dt 0.1 
ParticleSystems.exe -input system9_01_hose.txt -refresh 0.05 -dt 0.05
ParticleSystems.exe -input system9_01_hose.txt -refresh 0.1  -dt 0.1  -motion_blur
ParticleSystems.exe -input system9_01_hose.txt -refresh 0.05 -dt 0.05 -motion_blur
ParticleSystems.exe -input system9_02_hose_gravity.txt -refresh 0.05 -dt 0.05 -draw_vectors 0.1
ParticleSystems.exe -input system9_02_hose_gravity.txt -refresh 0.05 -dt 0.05 -motion_blur
ParticleSystems.exe -input system9_03_hose_force.txt -refresh 0.05 -dt 0.05 -draw_vectors 0.1
ParticleSystems.exe -input system9_03_hose_force.txt -refresh 0.05 -dt 0.05 -motion_blur
ParticleSystems.exe -input system9_04_circle_euler.txt -refresh 0.1  -dt 0.1  -integrator_color -draw_vectors 0.02
ParticleSystems.exe -input system9_04_circle_euler.txt -refresh 0.05 -dt 0.05 -integrator_color -motion_blur
ParticleSystems.exe -input system9_04_circle_euler.txt -refresh 0.01 -dt 0.01 -integrator_color -motion_blur
ParticleSystems.exe -input system9_05_circle_midpoint.txt -refresh 0.1  -dt 0.1  -integrator_color -draw_vectors 0.02
ParticleSystems.exe -input system9_05_circle_midpoint.txt -refresh 0.05 -dt 0.05 -integrator_color -motion_blur
ParticleSystems.exe -input system9_05_circle_midpoint.txt -refresh 0.01 -dt 0.01 -integrator_color -motion_blur
ParticleSystems.exe -input system9_08_fire.txt -refresh 0.05 -dt 0.05  -motion_blur