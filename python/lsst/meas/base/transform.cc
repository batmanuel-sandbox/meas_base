/* 
 * LSST Data Management System
 * Copyright 2008-2016  AURA/LSST.
 * 
 * This product includes software developed by the
 * LSST Project (http://www.lsst.org/).
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the LSST License Statement and 
 * the GNU General Public License along with this program.  If not, 
 * see <https://www.lsstcorp.org/LegalNotices/>.
 */

#include <pybind11/pybind11.h>
//#include <pybind11/stl.h>

#include "lsst/meas/base/Transform.h"

namespace py = pybind11;
using namespace pybind11::literals;

namespace lsst {
namespace meas {
namespace base {

PYBIND11_PLUGIN(_transform) {
    py::module mod("_transform", "Python wrapper for afw _transform library");

    /* Module level */
    py::class_<BaseTransform> cls(mod, "BaseTransform");

    /* Member types and enums */

    /* Constructors */

    /* Operators */
    cls.def("__call__", [](BaseTransform const & self,
                           afw::table::SourceCatalog const & inputCatalog,
                           afw::table::BaseCatalog & outputCatalog,
                           afw::image::Wcs const & wcs,
                           afw::image::Calib const & calib) {
            return self(inputCatalog, outputCatalog, wcs, calib);
        }, "inputCatalog"_a, "outputCatalog"_a, "wcs"_a, "calib"_a);

    /* Members */

    return mod.ptr();
}

}}}     // lsst::meas::base
