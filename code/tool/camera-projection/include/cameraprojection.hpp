/**
 * camera-projection - Tool to find projection matrix of camera.
 * Copyright (C) 2016 Chalmers Revere
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef CORE_TOOL_CAMERAPROJECTION_HPP_
#define CORE_TOOL_CAMERAPROJECTION_HPP_

#include <memory>
#include <opendavinci/odcore/wrapper/Eigen.h>

#include <opendavinci/odcore/base/module/TimeTriggeredConferenceClientModule.h>
#include <opendavinci/odcore/data/Container.h>

#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include "inverseperspectivemapping.hpp"

namespace opendlv {
namespace core {
namespace tool {

void LogMouseClicks(int32_t , int32_t, int32_t, int32_t, void*);
void ProjectMouseClicks(int32_t, int32_t, int32_t, int32_t, void*);

struct MouseParams
{
  Eigen::MatrixXd points;
  uint8_t iterator;
  
  MouseParams();
  ~MouseParams();
};

class CameraProjection
: public odcore::base::module::TimeTriggeredConferenceClientModule{
 public:
  CameraProjection(int32_t const &, char **);
  CameraProjection(CameraProjection const &) = delete;
  CameraProjection &operator=(CameraProjection const &) = delete;
  virtual ~CameraProjection();

  virtual void nextContainer(odcore::data::Container &);

 private:
  void setUp();
  void tearDown();

  odcore::data::dmcp::ModuleExitCodeMessage::ModuleExitCode body();
  void Calibrate();
  void Config();
  void Save();
  void Project();
  void ReadMatrix();
  void Warp();
  void SavePerspectivePoints(std::string a_path);

  double m_recHeight;
  double m_recWidth;
  double m_recPosX;
  double m_recPosY;
  Eigen::MatrixXd m_aMatrix;
  Eigen::MatrixXd m_bMatrix;
  Eigen::MatrixXd m_projectionMatrix;

  bool m_applyWarp;
  int m_point;
  std::vector<cv::Point2f> m_regionPoints;
  std::vector<cv::Point2f> m_outputPoints;

  cv::Size m_inputSize;
  cv::Size m_outputSize;

  std::string m_warpPointsFileName;
  std::string m_leftWarpPointsFileName;
  std::string m_rightWarpPointsFileName;

  std::string m_transformationMatrixFileName;
  std::string m_leftTransformationMatrixFileName;
  std::string m_rightTransformationMatrisFileName;

  std::string m_path;

  bool m_initialized;

};

} // tools
} // core
} // opendlv

#endif
