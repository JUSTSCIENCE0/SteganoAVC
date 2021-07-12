#pragma once

#include <gst/gst.h>
#include <gst/base/gstbasetransform.h>

#define VERSION "0.0.1"

G_BEGIN_DECLS

#define GST_TYPE_STGNAVC (gst_stgnavc_get_type())
#define GST_STGNAVC(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), GST_TYPE_STGNAVC, GstStgnAVC))
#define GST_STGNAVC_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), GST_TYPE_STGNAVC, GstStgnAVCClass))
#define GST_IS_STGNAVC(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), GST_TYPE_STGNAVC))
#define GST_IS_STGNAVC_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), GST_TYPE_STGNAVC))

typedef struct _GstStgnAVCClass GstStgnAVCClass;
typedef struct _GstStgnAVC      GstStgnAVC;

struct _GstStgnAVC
{
    GstBaseTransform m_parent_struct;

    //Engine here
};

struct _GstStgnAVCClass
{
    GstBaseTransformClass m_parent_class;
};

GType gst_stgnavc_get_type(void);

G_END_DECLS