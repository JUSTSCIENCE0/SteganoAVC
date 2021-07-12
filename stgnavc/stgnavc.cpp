#include <gst/gst.h>
#include "stgnavc.h"

GST_DEBUG_CATEGORY_STATIC(gst_stgnavc_debug);
#define GST_CAT_DEFAULT gst_stgnavc_debug

/* Filter signals and args */
enum
{
    /* FILL ME */
    LAST_SIGNAL
};

enum
{
	PROP_0,
	PROP_TEST
};

#define FORMATS "I420, Y42B, YUY2, UYVY, YV12, NV12, NV21" 

static GstStaticPadTemplate sink_factory = GST_STATIC_PAD_TEMPLATE("sink",
    GST_PAD_SINK,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS("video/x-raw, "
        "format = (string) { " FORMATS " }, "
        "framerate = (fraction) [0, MAX], "
        "width = (int) [ 16, MAX ], " "height = (int) [ 16, MAX ]")
);

static GstStaticPadTemplate src_factory = GST_STATIC_PAD_TEMPLATE("src",
    GST_PAD_SRC,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS("video/x-h264, "
        "stream-format = (string) byte-stream, "
        "alignment = (string) au, "
        "parsed = (string) false")
);

#define gst_stgnavc_parent_class parent_class
G_DEFINE_TYPE(GstStgnAVC, gst_stgnavc, GST_TYPE_BASE_TRANSFORM);

static void gst_stgnavc_finalize(GObject* object);
static void gst_stgnavc_set_property(GObject* object, guint prop_id, const GValue* value, GParamSpec* pspec);
static void gst_stgnavc_get_property(GObject* object, guint prop_id, GValue* value, GParamSpec* pspec);

static GstStateChangeReturn gst_stgnavc_change_state(GstElement* element, GstStateChange transition);
static GstFlowReturn gst_stgnavc_sink_chain(GstPad* pad, GstObject* obj, GstBuffer* buffer);
static gboolean gst_stgnavc_sink_event(GstPad* pad, GstObject* parent, GstEvent* event);
static gboolean gst_stgnavc_src_event(GstPad* pad, GstObject* parent, GstEvent* event);

static void gst_stgnavc_class_init(GstStgnAVCClass* stgnclass)
{
    GObjectClass* gst_object_class;
    GstElementClass* gstelement_class;
     
    gst_object_class = G_OBJECT_CLASS(stgnclass);
    gstelement_class = GST_ELEMENT_CLASS(stgnclass);

    gst_object_class->set_property = gst_stgnavc_set_property;
    gst_object_class->get_property = gst_stgnavc_get_property;
    gst_object_class->finalize     = gst_stgnavc_finalize;
    gstelement_class->change_state = gst_stgnavc_change_state;

    gst_element_class_set_static_metadata(gstelement_class,
        "Steganografy AVC Encoder", "Codec/Encoder/Video", "Steganografy AVC Encoder",
        "Yakov Usoltsev");

    gst_element_class_add_pad_template(gstelement_class,
        gst_static_pad_template_get(&sink_factory));
    gst_element_class_add_pad_template(gstelement_class,
        gst_static_pad_template_get(&src_factory));

    g_object_class_install_property(gst_object_class, PROP_TEST,
        g_param_spec_string("test-option",
            "test-option",
            "This is test option",
            "",
            (GParamFlags)(G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS)));
}

static void gst_stgnavc_init(GstStgnAVC* stgn)
{
    //Init engine here
}

static void gst_stgnavc_finalize(GObject* object)
{
    GstStgnAVC* stgn = GST_STGNAVC(object);

    //Clear engine here
}

static void gst_stgnavc_set_property(GObject* object, guint prop_id, const GValue* value, GParamSpec* pspec)
{
    GstStgnAVC* stgn = GST_STGNAVC(object);

    //Send param to engine here
}

static void gst_stgnavc_get_property(GObject* object, guint prop_id, GValue* value, GParamSpec* pspec)
{
    GstStgnAVC* stgn = GST_STGNAVC(object);

    //Read param from engine here
}

static GstStateChangeReturn gst_stgnavc_change_state(GstElement* element, GstStateChange transition)
{
    g_return_val_if_fail(GST_IS_STGNAVC(element), GST_STATE_CHANGE_FAILURE);

    GstStgnAVC* stgn = GST_STGNAVC(element);
    GstStateChangeReturn result = GST_STATE_CHANGE_SUCCESS;

    //change engine state here
    switch (transition)
    {
    case GST_STATE_CHANGE_NULL_TO_READY:
        //something
        break;

    case GST_STATE_CHANGE_READY_TO_PAUSED:
        //something
        break;

    case GST_STATE_CHANGE_PAUSED_TO_PLAYING:
        //something
        break;

    default:
        break;
    }

    result = GST_ELEMENT_CLASS(parent_class)->change_state(element, transition);

    switch (transition)
    {
    case GST_STATE_CHANGE_PLAYING_TO_PAUSED:
        //something
        break;

    case GST_STATE_CHANGE_PAUSED_TO_READY:
        //something
        break;

    case GST_STATE_CHANGE_READY_TO_NULL:
        //something
        break;

    default:
        break;
    }

    return result;
}

static GstFlowReturn gst_stgnavc_sink_chain(GstPad* pad, GstObject* obj, GstBuffer* buffer)
{
    return GST_FLOW_OK;
}

static gboolean gst_stgnavc_sink_event(GstPad* pad, GstObject* parent, GstEvent* event)
{
    return true;
}

static gboolean gst_stgnavc_src_event(GstPad* pad, GstObject* parent, GstEvent* event)
{
    return true;
}

/* entry point to initialize the plug-in
 * initialize the plug-in itself
 * register the element factories and other features
 */
static gboolean stgnavc_init(GstPlugin* stgnavc)
{
    GST_DEBUG_CATEGORY_INIT(gst_stgnavc_debug, "stgnavc",
        0, "Steganography AVC Encoder");

    return gst_element_register(stgnavc, "stgnavc", GST_RANK_NONE,
        GST_TYPE_STGNAVC);
}

#ifndef PACKAGE
#define PACKAGE "stgnavc"
#endif

GST_PLUGIN_DEFINE(
    GST_VERSION_MAJOR,
    GST_VERSION_MINOR,
    stgnavc,
    "Steganography AVC Encoder",
    stgnavc_init,
    VERSION,
    GST_LICENSE_UNKNOWN,
    "stgnavc.dll",
    "Yakov Usoltsev"
)