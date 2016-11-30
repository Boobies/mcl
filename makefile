# Copyright 2016 Bogdan Barbu
#
# This file is part of the Modern C Library.
#
# The Modern C Library is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# The Modern C Library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with the Modern C Library.  If not, see <http://www.gnu.org/licenses/>.

MCL_SRC_FILES := exceptions.c
MCL_OBJ_FILES := $(MCL_SRC_FILES:.c=.o)
MCL_LIB_FILE := libmcl.a

MCL_DBK_FILES := mcl.xml
MAN_VOL := 3

SRC_FILES += $(MCL_SRC_FILES)
LIB_FILES += $(MCL_LIB_FILE)
DBK_FILES += $(MCL_DBK_FILES)

include makebs/makebs.mk

INSTALL := $(INC_DIR) $(LIB_DIR) $(MAN_DIR)

$(LIB_DIR)/$(MCL_LIB_FILE): $(MCL_OBJ_FILES:%=$(OBJ_DIR)/%) | $(LIB_DIR)
	$(AR) $(ARFLAGS) $@ $?

