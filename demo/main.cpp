// Debug Settings
// --------------------------------------
//#define RYAO_ARROW_DEBUG
#define RYAO_REFERENCE_PLANE_DEBUG
// Include Header Files
// --------------------------------------

#include <Viewer.h>
#include <RYAO.h>
#include <Logger.h>
#include <Timer.h>
#include "Scene/BunnyDrop.h"
#include "Scene/PBDBunnyDrop.h"
#include "Scene/PBDColth.h"

int main()
{
    Ryao::Logger::Init();
    Ryao::Camera camera(glm::vec3(0.0, 0.0, 8.0));
    Ryao::Viewer viewer(camera);

    viewer.setUseGUI(false);
    viewer.init();

    viewer.setReferencePlane(20);

    // add these shapes to simulation by
    // SOLVER::addKinematicCollisionObject

// For implicit Euler Simulation
//    Ryao::Simulation* simulation = new Ryao::BunnyDrop();
//    simulation->buildScene();
//
//    viewer.setSimulation(simulation);
//
//    viewer.registerShapeToViewer();
//    viewer.registerTETMeshToViewer();

// For XPBD Simulation
    Ryao::PBDSimulation* simulation = new Ryao::PBDBunnyDrop();
    //Ryao::PBDSimulation* simulation = new Ryao::PBDCloth();
    simulation->buildScene();

    viewer.setSimulation(simulation);

    viewer.registerShapeToViewer();
    viewer.registerDynamicMeshToViewer();

    viewer.launch();

    Ryao::Timer::printTimings();

    return 0;
}